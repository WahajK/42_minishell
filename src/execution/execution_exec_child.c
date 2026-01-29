/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_exec_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:04:48 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 01:30:46 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_directory(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
		return (0);
	return (S_ISDIR(path_stat.st_mode));
}

static void	handle_direct_path_error(char *arg)
{
	if (is_directory(arg))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exit(126);
	}
	if (access(arg, F_OK) == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
}

static void	exec_or_die(char *path, char **args, char *cmd, char **envp)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		free(path);
		exit(126);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	exit(1);
}

void	exec_child_command(t_command *cmd, t_data *data, t_pipe_ctx *ctx)
{
	char	*path;
	int		i;

	i = 0;
	while (cmd->args[i] && cmd->args[i][0] == '\0')
		i++;
	if (!cmd->args[i])
		exit(0);
	path = find_command_path(cmd->args[i], data);
	if (!path)
	{
		if (ft_strchr(cmd->args[i], '/'))
			handle_direct_path_error(cmd->args[i]);
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(cmd->args[i], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	exec_or_die(path, cmd->args + i, cmd->args[i], ctx->envp);
}
