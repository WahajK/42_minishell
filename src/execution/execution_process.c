/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:48:04 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 00:25:07 by muhakhan         ###   ########.fr       */
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

static int	fork_and_execute(char *path, char **args, char **envp,
	t_redir *redirs)
{
	pid_t	pid;
	int		status;

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

int	execute_external_command(char **args, char **envp, t_data *data,
	t_redir *redirs)
{
	char			*path;
	struct stat		path_stat;
	int				i;

	i = 0;
	while (args[i] && args[i][0] == '\0')
		i++;
	if (!args[i])
		return (0);
	path = find_command_path(args[i], data);
	if (!path)
	{
		if (ft_strchr(args[i], '/'))
		{
			if (stat(args[i], &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(args[i], 2);
				ft_putstr_fd(": Is a directory\n", 2);
				return (126);
			}
			if (access(args[i], F_OK) == 0)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(args[i], 2);
				ft_putstr_fd(": Permission denied\n", 2);
				return (126);
			}
		}
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(args[i], 2);
		ft_putstr_fd("\n", 2);
		return (127);
	}
	if (stat(path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(args[i], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		free(path);
		return (126);
	}
	return (fork_and_execute(path, args + i, envp, redirs));
}
