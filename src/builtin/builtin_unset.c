/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:03:04 by okhan             #+#    #+#             */
/*   Updated: 2026/01/26 22:14:35 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	remove_env_var(t_env **env_list, char *key)
{
	t_env	*curr;
	t_env	*prev;

	curr = *env_list;
	prev = NULL;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*env_list = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	builtin_unset(char **args, t_data *data)
{
	int	i;

	i = 1;
	while (args[i])
	{
		remove_env_var(&data->env_list, args[i]);
		i++;
	}
	return (0);
}
