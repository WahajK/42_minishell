/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 16:58:34 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->token = ft_strdup(value);
	if (!token->token)
	{
		free(token);
		return (NULL);
	}
	token->type = type;
	token->next = NULL;
	return (token);
}

char	*extract_quoted_word(char *input, int *len)
{
	char	quote;
	int		i;
	char	*word;

	quote = input[0];
	i = 1;
	while (input[i] && input[i] != quote)
		i++;
	if (input[i] == quote)
		i++;
	*len = i;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, input, i + 1);
	return (word);
}

int	process_word_char(char *input, int *i, char *word, int *j)
{
	if (input[*i] == '\\' && input[*i + 1])
	{
		word[(*j)++] = input[*i + 1];
		*i += 2;
		return (1);
	}
	if (should_end_word(input[*i]))
		return (0);
	word[(*j)++] = input[(*i)++];
	return (1);
}

t_token	*process_token(char *input, int *len)
{
	char	*value;
	t_token	*token;

	if (is_operator(input[0]))
	{
		value = extract_operator(input, len);
		token = create_token(value, get_operator_type(value));
	}
	else if (input[0] == '\'' || input[0] == '"')
	{
		value = extract_quoted_word(input, len);
		token = create_token(value, TOK_WORD);
	}
	else
	{
		value = extract_word(input, len);
		token = create_token(value, TOK_WORD);
	}
	free(value);
	return (token);
}

t_token	*lexer(char *input)
{
	t_token	*head;
	t_token	*token;
	int		len;
	int		i;

	head = NULL;
	i = 0;
	while (input[i])
	{
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (!input[i])
			break ;
		token = process_token(&input[i], &len);
		if (!token)
			return (free_token_list(head), NULL);
		add_token_to_list(&head, token);
		i += len;
	}
	return (head);
}
