/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:01:31 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 20:32:13 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*resolve_cd_path(char **args, t_data *data)
{
	char	*arg;
	char	*home;

	arg = args[1];
	if (!arg)
	{
		home = get_env_value(data, "HOME");
		if (!home)
			return (NULL);
		return (ft_strdup(home));
	}
	if (arg[0] == '~')
	{
		home = get_env_value(data, "HOME");
		if (!home)
			return (NULL);
		if (arg[1] == '\0')
			return (ft_strdup(home));
		return (ft_strjoin(home, arg + 1));
	}
	return (ft_strdup(arg));
}

static int	change_dir_and_update(char *path, t_data *data, int print_pwd)
{
	char	cwd[CWD_BUFFER_SIZE];
	char	old_cwd[CWD_BUFFER_SIZE];

	if (getcwd(old_cwd, CWD_BUFFER_SIZE) == NULL)
		old_cwd[0] = '\0';
	if (chdir(path) != 0)
	{
		perror("minishell: cd");
		free(path);
		return (1);
	}
	free(path);
	if (getcwd(cwd, CWD_BUFFER_SIZE) != NULL)
	{
		update_env(data, "OLDPWD", old_cwd);
		update_env(data, "PWD", cwd);
		if (print_pwd)
			printf("%s\n", cwd);
	}
	return (0);
}

int	builtin_cd(char **args, t_data *data)
{
	char	*path;
	int		print_oldpwd;

	print_oldpwd = args[1] && ft_strcmp(args[1], "-") == 0;
	if (print_oldpwd)
	{
		path = get_env_value(data, "OLDPWD");
		if (!path)
			return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), 1);
		path = ft_strdup(path);
	}
	else
	{
		path = resolve_cd_path(args, data);
		if (!path)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	}
	return (change_dir_and_update(path, data, print_oldpwd));
}
