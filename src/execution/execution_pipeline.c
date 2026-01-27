/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:06:25 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:15:40 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	child_worker(t_command *cmd,
	t_data *data, int pipe_fds[2], int prev_fd, char **envp)
{
	char	*path;

	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (cmd->next)
	{
		close(pipe_fds[0]);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
	}
	if (apply_redirections(cmd->redirs) == -1)
		exit(1);
	path = find_command_path(cmd->args[0], data);
	if (!path)
		exit(127);
	execve(path, cmd->args, envp);
	perror("execve");
	free(path);
	exit(1);
}


void	execute_pipeline(t_command *cmds, t_data *data)
{
	int		pipe_fds[2];
	int		prev_fd;
	pid_t	pid;
	char	**envp;

	envp = env_list_to_envp(data->env_list);
	if (!envp)
		return ;
	prev_fd = -1;
	while (cmds)
	{
		if (cmds->next && pipe(pipe_fds) == -1)
			return (perror("pipe"), ft_free_split(envp));
		pid = fork();
		if (pid == -1)
			return (perror("fork"), ft_free_split(envp));
		if (pid == 0)
			child_worker(cmds, data, pipe_fds, prev_fd, envp);
		if (prev_fd != -1)
			close(prev_fd);
		if (cmds->next)
		{
			close(pipe_fds[1]);
			prev_fd = pipe_fds[0];
		}
		cmds = cmds->next;
	}
	ft_free_split(envp);
	while (wait(NULL) > 0)
		;
}
