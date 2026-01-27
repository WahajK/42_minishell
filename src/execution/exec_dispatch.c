/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:01:57 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 15:36:24 by okhan            ###   ########.fr       */
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
