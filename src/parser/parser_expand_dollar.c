/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_dollar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 00:53:20 by okhan             #+#    #+#             */
/*   Updated: 2026/01/29 00:54:06 by okhan            ###   ########.fr       */
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

int	handle_dollar(char *str, int *i, t_data *data, char **res)
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
