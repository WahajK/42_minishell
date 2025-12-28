/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:48:04 by okhan             #+#    #+#             */
/*   Updated: 2025/12/28 18:21:33 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	void	child_process_exec(char *path, char **args, char **envp)
{
	// execve replaces the current process image with a new one
	execve(path, args, envp);
	// If execution reaches here, execve failed
	// Print error message to stderr (fd 2)
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(args[0], 2);
	ft_putstr_fd("\n", 2);
	// Exit the child process with a specific error code (127 for command not found)
	exit(127);
}

int	execute_external_command(char **args, char ** envp, t_data *data)
{
	pid_t	pid;
	int		status;
	char	*path;

	// 1. Find the full path to the command
	path = find_commadnd_path(args[0], data);
	if (!path)
		return (127);
	// 2. Fork the process
	pid = fork();
	if (pid  == -1)
	{
		perror("fork failed");
		free(path);
		return (1);
	}
	if (pid == 0)
		child_process_exec(path, args, envp);

	waitpid(pid, &status, 0);
	free(path);

	if (WIFEXITED(status))
		return(WEXITSTATUS(status));
	return (1);
}