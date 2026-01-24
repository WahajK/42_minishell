/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/24 22:56:04 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	add_command_to_list(t_command **head, t_command *new_cmd)
{
	t_command	*curr;

	if (!*head)
	{
		*head = new_cmd;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_cmd;
}

static t_command	*parse_pipeline(t_token **tokens)
{
	t_command	*head;
	t_command	*cmd;

	head = NULL;
	while (*tokens && (*tokens)->type != TOK_EOF)
	{
		cmd = parse_simple_command(tokens);
		if (!cmd)
			return (free_command_list(head), NULL);
		add_command_to_list(&head, cmd);
		if (*tokens && (*tokens)->type == TOK_PIPE)
		{
			*tokens = (*tokens)->next;
			if (!*tokens || (*tokens)->type == TOK_PIPE)
			{
				printf("minishell: syntax error near unexpected token `|'\n");
				free_command_list(head);
				return (NULL);
			}
		}
		else
			break ;
	}
	return (head);
}

t_command	*parse_input(char *input)
{
	t_token		*tokens;
	t_command	*commands;

	if (!input || !*input)
		return (NULL);
	tokens = lexer(input);
	if (!tokens)
		return (NULL);
	commands = parse_pipeline(&tokens);
	free_token_list(tokens);
	return (commands);
}

int	check_syntax_errors(t_token *tokens)
{
	t_token	*curr;

	curr = tokens;
	while (curr)
	{
		if (curr->type == TOK_PIPE)
		{
			if (!curr->next || curr->next->type == TOK_PIPE)
			{
				printf("minishell: syntax error near unexpected token `|'\n");
				return (1);
			}
		}
		if (curr->type == TOK_LT || curr->type == TOK_GT
			|| curr->type == TOK_DGT || curr->type == TOK_DLT)
		{
			if (!curr->next || curr->next->type != TOK_WORD)
			{
				printf("minishell: syntax error near unexpected token\n");
				return (1);
			}
		}
		curr = curr->next;
	}
	return (0);
}
