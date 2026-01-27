/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:01:31 by okhan             #+#    #+#             */
/*   Updated: 2026/01/26 22:02:11 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	void	update_env(t_data *data, char *key, char *value)
{
	t_env	*curr;

	curr = data->env_list;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			return ;
		}
		curr = curr->next;
	}
}

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
