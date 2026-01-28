/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:00:00 by okhan             #+#    #+#             */
/*   Updated: 2026/01/26 21:43:51 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	env_count(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

static char	*join_env(t_env *env)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(env->key, "=");
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, env->value);
	free(tmp);
	return (res);
}

char	**env_list_to_envp(t_env *env)
{
	char	**envp;
	int		i;

	envp = malloc(sizeof(char *) * (env_count(env) + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (env)
	{
		envp[i] = join_env(env);
		if (!envp[i])
			return (ft_free_split(envp), NULL);
		env = env->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
