/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:20:38 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 01:21:37 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	execute_builtin(char **args, t_data *data)
{
	char	*cmd;

	if (!args || !args[0])
		return (0);
	cmd = args[0];
	if (ft_strcmp(cmd, "echo") == 0)
		return (builtin_echo(args));
	if (ft_strcmp(cmd, "cd") == 0)
		return (builtin_cd(args, data));
	if (ft_strcmp(cmd, "pwd") == 0)
		return (my_pwd(args));
	if (ft_strcmp(cmd, "export") == 0)
		return (builtin_export(args, data));
	if (ft_strcmp(cmd, "unset") == 0)
		return (builtin_unset(args, data));
	if (ft_strcmp(cmd, "env") == 0)
		return (builtin_env(args, data));
	if (ft_strcmp(cmd, "exit") == 0)
		return (builtin_exit(args, data));
	return (1);
}

int	exec_builtin_with_redirs(t_command *cmd, t_data *data)
{
	int		status;
	int		saved_out;
	int		saved_in;

	saved_out = dup(STDOUT_FILENO);
	saved_in = dup(STDIN_FILENO);
	if (apply_redirections(cmd->redirs) == -1)
	{
		dup2(saved_out, STDOUT_FILENO);
		dup2(saved_in, STDIN_FILENO);
		close(saved_out);
		close(saved_in);
		return (1);
	}
	status = execute_builtin(cmd->args, data);
	dup2(saved_out, STDOUT_FILENO);
	dup2(saved_in, STDIN_FILENO);
	close(saved_out);
	close(saved_in);
	cmd->exit_status = status;
	return (status);
}
