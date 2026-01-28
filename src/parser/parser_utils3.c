/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:52:27 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 17:04:37 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	append_str(char **result, const char *add)
{
	char		*tmp;
	const char	*suffix;

	if (add)
		suffix = add;
	else
		suffix = "";
	tmp = ft_strjoin(*result, suffix);
	if (!tmp)
		return (0);
	free(*result);
	*result = tmp;
	return (1);
}

int	append_char(char **result, char c)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	return (append_str(result, buf));
}

int	is_builtin_cmd(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

char	*extract_word(char *input, int *len)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	word = malloc(sizeof(char) * (ft_strlen(input) + 1));
	if (!word)
		return (NULL);
	while (input[i] && process_word_char(input, &i, word, &j))
		;
	word[j] = '\0';
	*len = i;
	return (word);
}
