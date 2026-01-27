/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:06:25 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:53:56 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	setup_child_fds(t_command *cmd, t_pipe_ctx *ctx)
{
	if (ctx->prev_fd != -1)
	{
		dup2(ctx->prev_fd, STDIN_FILENO);
		close(ctx->prev_fd);
	}
	if (cmd->next)
	{
		close(ctx->pipe_fds[0]);
		dup2(ctx->pipe_fds[1], STDOUT_FILENO);
		close(ctx->pipe_fds[1]);
	}
}

static void	exec_child_command(t_command *cmd, t_data *data, t_pipe_ctx *ctx)
{
	char	*path;

	path = find_command_path(cmd->args[0], data);
	if (!path)
		exit(127);
	execve(path, cmd->args, ctx->envp);
	perror("execve");
	free(path);
	exit(1);
}

static void	child_worker(t_command *cmd, t_data *data, t_pipe_ctx *ctx)
{
	setup_child_fds(cmd, ctx);
	if (apply_redirections(cmd->redirs) == -1)
		exit(1);
	exec_child_command(cmd, data, ctx);
}

static int	init_pipeline_ctx(t_pipe_ctx *ctx, t_data *data)
{
	ctx->envp = env_list_to_envp(data->env_list);
	if (!ctx->envp)
		return (-1);
	ctx->prev_fd = -1;
	return (0);
}

static int	run_pipeline_loop(t_command *cmds, t_data *data, t_pipe_ctx *ctx)
{
	pid_t	pid;

	while (cmds)
	{
		if (cmds->next && pipe(ctx->pipe_fds) == -1)
			return (perror("pipe"), ft_free_split(ctx->envp), -1);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), ft_free_split(ctx->envp), -1);
		if (pid == 0)
			child_worker(cmds, data, ctx);
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

void	execute_pipeline(t_command *cmds, t_data *data)
{
	t_pipe_ctx	ctx;

	if (init_pipeline_ctx(&ctx, data) == -1)
		return ;
	if (run_pipeline_loop(cmds, data, &ctx) == -1)
		return ;
	ft_free_split(ctx.envp);
	while (wait(NULL) > 0)
		;
}
