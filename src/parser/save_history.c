/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:48:15 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 17:57:23 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	save_command_to_history(const char *command)
{
	int		fd;
	size_t	len;
	char	*path;

	if (!command || *command == '\0')
		return ;
	path = get_history_path();
	if (!path)
	{
		printf("minishell: could not resolve history path\n");
		return ;
	}
	fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(path);
	if (fd < 0)
	{
		printf("minishell: could not write to history file\n");
		return ;
	}
	len = ft_strlen(command);
	write(fd, command, len);
	write(fd, "\n", 1);
	close(fd);
}

int	is_real_word_end(char c)
{
	return (is_operator(c) || c == ' ' || c == '\t');
}

void	process_quoted_in_word(char *input, int *i, char *word, int *j)
{
	char	quote;

	quote = input[*i];
	(*i)++;
	while (input[*i] && input[*i] != quote)
		word[(*j)++] = input[(*i)++];
	if (input[*i] == quote)
		(*i)++;
}
