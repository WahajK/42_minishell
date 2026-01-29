/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 00:50:56 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 01:55:43 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	process_single_quote(char *str, int *i, char **res)
{
	(*i)++;
	while (str[*i] && str[*i] != '\'')
	{
		if (!append_char(res, str[*i]))
			return (0);
		(*i)++;
	}
	if (str[*i] == '\'')
		(*i)++;
	return (1);
}

int	process_double_quote(char *str, int *i, t_data *data, char **res)
{
	(*i)++;
	while (str[*i] && str[*i] != '"')
	{
		if (str[*i] == '$')
		{
			if (!handle_dollar(str, i, data, res))
				return (0);
		}
		else
		{
			if (!append_char(res, str[*i]))
				return (0);
			(*i)++;
		}
	}
	if (str[*i] == '"')
		(*i)++;
	return (1);
}
