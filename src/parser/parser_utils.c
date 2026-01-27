/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/24 22:45:24 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->token);
		free(tmp);
	}
}

void	free_redir_list(t_redir *head)
{
	t_redir	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->file);
		free(tmp);
	}
}

void	free_command(t_command *cmd)
{
	if (!cmd)
		return ;
	if (cmd->args)
		ft_free_split(cmd->args);
	if (cmd->redirs)
		free_redir_list(cmd->redirs);
	free(cmd);
}

void	free_command_list(t_command *head)
{
	t_command	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free_command(tmp);
	}
}

char	*skip_whitespaces(char *input)
{
	while (*input && (*input == ' ' || *input == '\t'))
		input++;
	return (input);
}

int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type == TOK_WORD)
	{
		count++;
		tokens = tokens->next;
	}
	return (count);
}

char	*remove_quotes(char *str)
{
	char	*result;
	char	quote;
	int		i;
	int		j;

	if (!str || (str[0] != '\'' && str[0] != '"'))
		return (ft_strdup(str));
	quote = str[0];
	i = 1;
	j = 0;
	while (str[i] && str[i] != quote)
		i++;
	result = malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	i = 1;
	while (str[i] && str[i] != quote)
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}
