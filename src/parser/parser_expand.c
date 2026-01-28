/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/29 00:17:11 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_exit_code(char **res, int code)
{
	char	*num;
	int		ok;

	num = ft_itoa(code);
	if (!num)
		return (0);
	ok = append_str(res, num);
	free(num);
	return (ok);
}

static int	handle_dollar_pid(char **res, int *i)
{
	char	*pid_str;
	int		ok;

	pid_str = ft_itoa(getpid());
	if (!pid_str)
		return (0);
	ok = append_str(res, pid_str);
	free(pid_str);
	*i += 2;
	return (ok);
}

static int	handle_dollar_env(char *str, int *i, t_data *data, char **res)
{
	int		start;
	char	*name;

	if (!ft_isalpha(str[*i + 1]) && str[*i + 1] != '_')
		return (append_char(res, str[(*i)++]));
	start = *i + 1;
	while (str[start] && (ft_isalnum(str[start]) || str[start] == '_'))
		start++;
	name = ft_substr(str, *i + 1, start - (*i + 1));
	if (!name)
		return (0);
	if (!append_str(res, get_env_value(data, name)))
		return (free(name), 0);
	free(name);
	*i = start;
	return (1);
}

static int	handle_dollar(char *str, int *i, t_data *data, char **res)
{
	if (str[*i + 1] == '?')
	{
		*i += 2;
		return (handle_exit_code(res, data->last_exit_code));
	}
	if (str[*i + 1] == '$')
		return (handle_dollar_pid(res, i));
	return (handle_dollar_env(str, i, data, res));
}

static int	process_single_quote(char *str, int *i, char **res)
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

static int	process_double_quote(char *str, int *i, t_data *data, char **res)
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
		if (str[i] == '\'')
		{
			if (!process_single_quote(str, &i, &res))
				return (free(res), NULL);
		}
		else if (str[i] == '"')
		{
			if (!process_double_quote(str, &i, data, &res))
				return (free(res), NULL);
		}
		else if (str[i] == '$')
		{
			if (!handle_dollar(str, &i, data, &res))
				return (free(res), NULL);
		}
		else
		{
			if (!append_char(&res, str[i]))
				return (free(res), NULL);
			i++;
		}
	}
	return (res);
}
