/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:01:57 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 01:21:58 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	exec_redir_only(t_redir *redirs)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
	{
		if (apply_redirections(redirs) == -1)
			exit(1);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

static int	exec_external_with_env(t_command *cmd, t_data *data)
{
	char	**envp;
	int		status;

	envp = env_list_to_envp(data->env_list);
	status = execute_external_command(cmd->args, envp, data, cmd->redirs);
	ft_free_split(envp);
	cmd->exit_status = status;
	return (status);
}

int	execute_command(t_command *cmd, t_data *data)
{
	if (!cmd)
		return (0);
	if (!cmd->args || !cmd->args[0])
	{
		if (cmd->redirs)
			return (exec_redir_only(cmd->redirs));
		return (0);
	}
	if (cmd->is_builtin)
		return (exec_builtin_with_redirs(cmd, data));
	return (exec_external_with_env(cmd, data));
}
