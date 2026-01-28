/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:58 by okhan             #+#    #+#             */
/*   Updated: 2026/01/28 16:48:48 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	t_env	*create_node_from_env(char *env_str)
{
	char	*equal_sign;
	char	*key;
	t_env	*node;

	equal_sign = ft_strchr(env_str, '=');
	if (!equal_sign)
		return (NULL);
	key = ft_strndup(env_str, equal_sign - env_str);
	node = ft_new_env_node(key, equal_sign + 1);
	free(key);
	return (node);
}

t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*current;
	t_env	*node;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (envp[i])
	{
		node = create_node_from_env(envp[i]);
		if (!node)
		{
			free_env_list(head);
			return (NULL);
		}
		if (!head)
			head = node;
		else
			current->next = node;
		current = node;
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
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void	update_env(t_data *data, char *key, char *value)
{
	t_env	*current;
	t_env	*new_node;

	if (!data || !key)
		return ;
	current = data->env_list;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		current = current->next;
	}
	new_node = ft_new_env_node(key, value);
	if (new_node)
	{
		new_node->next = data->env_list;
		data->env_list = new_node;
	}
}

void	init_shell_data(t_data *data, char **envp)
{
	data->env_list = init_env(envp);
	data->user_input = NULL;
	data->last_exit_code = 0;
	data->working_dir = getcwd(NULL, CWD_BUFFER_SIZE);
	if (!data->working_dir)
		clean_exit(1, "getcwd failed");
}
