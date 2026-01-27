/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:02:27 by okhan             #+#    #+#             */
/*   Updated: 2026/01/26 22:12:04 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	add_env_node(t_data *data, char *key, char *value)
{
	t_env	*new;
	t_env	*curr;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (!data->env_list)
		data->env_list = new;
	else
	{
		curr = data->env_list;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

int	builtin_export(char **args, t_data *data)
{
	char	*equal;
	char	*key;
	int		i;

	if (!args[1])
		return (builtin_env(args, data));
	i = 1;
	while (args[i])
	{
		equal = ft_strchr(args[i], '=');
		if (equal)
		{
			key = ft_strndup(args[i], equal - args[i]);
			update_env(data, key, equal + 1);
			free(key);
		}
		i++;
	}
	return (0);
}
