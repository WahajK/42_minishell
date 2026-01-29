/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:06:25 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 01:06:31 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	child_worker(t_command *cmd, t_data *data, t_pipe_ctx *ctx)
{
	setup_child_fds(cmd, ctx);
	if (apply_redirections(cmd->redirs) == -1)
		exit(1);
	if (!cmd->args || !cmd->args[0])
		exit(0);
	exec_child_command(cmd, data, ctx);
}

static int	init_pipeline_ctx(t_pipe_ctx *ctx, t_data *data)
{
	ctx->envp = env_list_to_envp(data->env_list);
	if (!ctx->envp)
		return (-1);
	ctx->prev_fd = -1;
	ctx->last_pid = -1;
	return (0);
}

static int	run_pipeline_loop(t_command *cmds, t_data *data, t_pipe_ctx *ctx)
{
	pid_t	pid;

	while (cmds)
	{
		if (cmds->next && pipe(ctx->pipe_fds) == -1)
			return (perror("pipe"), 1);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), 1);
		if (pid == 0)
			child_worker(cmds, data, ctx);
		ctx->last_pid = pid;
		if (ctx->prev_fd != -1)
			close(ctx->prev_fd);
		if (cmds->next)
		{
			close(ctx->pipe_fds[1]);
			ctx->prev_fd = ctx->pipe_fds[0];
		}
		cmds = cmds->next;
	}
	return (0);
}

int	execute_pipeline(t_command *cmds, t_data *data)
{
	t_pipe_ctx	ctx;
	int			status;
	int			last_status;
	pid_t		pid;

	if (init_pipeline_ctx(&ctx, data) == -1)
		return (1);
	if (run_pipeline_loop(cmds, data, &ctx) != 0)
		return (ft_free_split(ctx.envp), 1);
	ft_free_split(ctx.envp);
	last_status = 0;
	pid = wait(&status);
	while (pid > 0)
	{
		if (pid == ctx.last_pid)
		{
			if (WIFEXITED(status))
				last_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				last_status = 128 + WTERMSIG(status);
		}
		pid = wait(&status);
	}
	data->last_exit_code = last_status;
	return (last_status);
}
