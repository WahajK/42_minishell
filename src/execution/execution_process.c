/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:48:04 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:20:02 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	void	child_process_exec(char *path, char **args, char **envp,
	t_redir *redirs)
{
	if (apply_redirections(redirs) == -1)
		exit(1);
	execve(path, args, envp);
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(args[0], 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

int	execute_external_command(char **args, char **envp, t_data *data,
	t_redir *redirs)
{
	pid_t	pid;
	int		status;
	char	*path;

	path = find_command_path(args[0], data);
	if (!path)
		return (127);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free(path);
		return (1);
	}
	if (pid == 0)
		child_process_exec(path, args, envp, redirs);
	waitpid(pid, &status, 0);
	free(path);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
