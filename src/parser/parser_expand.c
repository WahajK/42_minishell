/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/29 01:26:58 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	process_char(char *str, int *i, t_data *data, char **res)
{
	if (str[*i] == '\'')
		return (process_single_quote(str, i, res));
	if (str[*i] == '"')
		return (process_double_quote(str, i, data, res));
	if (str[*i] == '$')
		return (handle_dollar(str, i, data, res));
	if (!append_char(res, str[*i]))
		return (0);
	(*i)++;
	return (1);
}

char	*expand_variables(char *str, t_data *data)
{
	char	*res;
	int		i;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (!process_char(str, &i, data, &res))
			return (free(res), NULL);
	}
	return (res);
}
