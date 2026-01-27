/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:01:31 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:24:19 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_cd(char **args, t_data *data)
{
	char	*path;
	char	cwd[CWD_BUFFER_SIZE];
	char	old_cwd[CWD_BUFFER_SIZE];

	path = args[1];
	if (!path)
		path = get_env_value(data, "HOME");
	if (!path)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	if (getcwd(old_cwd, CWD_BUFFER_SIZE) == NULL)
		old_cwd[0] = '\0';
	if (chdir(path) != 0)
	{
		perror("minishell: cd");
		return (1);
	}
	if (getcwd(cwd, CWD_BUFFER_SIZE) != NULL)
	{
		update_env(data, "OLDPWD", old_cwd);
		update_env(data, "PWD", cwd);
	}
	return (0);
}
