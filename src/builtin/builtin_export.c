/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:02:27 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 20:31:15 by muhakhan         ###   ########.fr       */
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

static char	*resolve_export_value(char *arg, char *next, int *skip_next)
{
	char	*equal;

	*skip_next = 0;
	equal = ft_strchr(arg, '=');
	if (!equal)
		return (NULL);
	if (*(equal + 1) != '\0')
		return (equal + 1);
	if (next && !ft_strchr(next, '='))
	{
		*skip_next = 1;
		return (next);
	}
	return ("\0");
}

static int	is_valid_identifier(char *key)
{
	int		i;

	if (!key || !key[0] || (!ft_isalpha(key[0]) && key[0] != '_'))
		return (0);
	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	process_export_arg(char *arg, char *next, t_data *data, int *skip)
{
	char	*equal;
	char	*key;
	char	*value;

	equal = ft_strchr(arg, '=');
	value = resolve_export_value(arg, next, skip);
	if (equal)
		key = ft_strndup(arg, equal - arg);
	else
		key = ft_strdup(arg);
	if (!is_valid_identifier(key))
	{
		fprintf(stderr, "minishell: export: `%s': not a valid identifier\n",
			arg);
		free(key);
		return (1);
	}
	if (equal && value)
		update_env(data, key, value);
	else if (!equal)
		update_env(data, key, "");
	free(key);
	return (0);
}

int	builtin_export(char **args, t_data *data)
{
	int		i;
	int		skip_next;
	int		status;

	if (!args[1])
		return (builtin_env(args, data));
	i = 1;
	status = 0;
	while (args[i])
	{
		if (process_export_arg(args[i], args[i + 1], data, &skip_next))
			status = 1;
		if (skip_next)
			i++;
		i++;
	}
	return (status);
}
