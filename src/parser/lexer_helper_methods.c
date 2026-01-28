/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper_methods.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:36:36 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 16:40:04 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == ';'
		|| c == '(' || c == ')');
}

void	add_token_to_list(t_token **head, t_token *new_token)
{
	t_token	*curr;

	if (!*head)
	{
		*head = new_token;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_token;
}

char	*extract_operator(char *input, int *len)
{
	char	*op;

	*len = 1;
	if ((input[0] == '>' && input[1] == '>') || (input[0] == '<'
			&& input[1] == '<') || (input[0] == '&' && input[1] == '&'))
		*len = 2;
	op = malloc(sizeof(char) * (*len + 1));
	if (!op)
		return (NULL);
	ft_strlcpy(op, input, *len + 1);
	return (op);
}

int	should_end_word(char c)
{
	return (is_operator(c) || c == ' ' || c == '\t' || c == '\'' || c == '"');
}

t_token_type	get_operator_type(char *op)
{
	if (ft_strcmp(op, "|") == 0)
		return (TOK_PIPE);
	if (ft_strcmp(op, "<") == 0)
		return (TOK_LT);
	if (ft_strcmp(op, ">") == 0)
		return (TOK_GT);
	if (ft_strcmp(op, ">>") == 0)
		return (TOK_DGT);
	if (ft_strcmp(op, "<<") == 0)
		return (TOK_DLT);
	if (ft_strcmp(op, "&&") == 0)
		return (TOK_AND);
	if (ft_strcmp(op, ";") == 0)
		return (TOK_SEMI_COL);
	if (ft_strcmp(op, "(") == 0)
		return (TOK_LPAREN);
	if (ft_strcmp(op, ")") == 0)
		return (TOK_RPAREN);
	return (TOK_UNKNOWN);
}
