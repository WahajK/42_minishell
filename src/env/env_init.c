/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:58 by okhan             #+#    #+#             */
/*   Updated: 2025/12/28 17:33:07 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_env	*ft_new_env_node(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = strdup(key);
	new->value = strdup(value);
	new->next = NULL;
	if (!new->key || !new->value)
	{
		if (new->key)
			free(new->key);
		if (new->value)
			free(new->value);
		free(new);
		return (NULL);
	}
	return (new);
}

t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*current;
	char	*equal_sign;
	char	*key;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (envp[i])
	{
		equal_sign = strchr(envp[i], '=');
		if (equal_sign)
		{
			key = strndup(envp[i], equal_sign - envp[i]);
			t_env *new_node;
			
			new_node = ft_new_env_node(key, equal_sign + 1);
			free(key);
			if (!new_node)
			{
				free_env_list(head);
				return (NULL);
			}
			if (!head)
				head = new_node;
			else
				current->next = new_node;
			current = new_node;
		}
		i++;
	}
	return (head);
}

char	*get_env_value(t_data *data, char *key)
{
	t_env	*current;

	if (!data || !key)
		return (NULL);
	current = data->env_list;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
