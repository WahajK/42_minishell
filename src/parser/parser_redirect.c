/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/24 22:52:47 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_redir	*create_redir(char *file, t_redir_type type)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = ft_strdup(file);
	if (!redir->file)
	{
		free(redir);
		return (NULL);
	}
	redir->type = type;
	redir->next = NULL;
	return (redir);
}

static void	add_redir_to_list(t_redir **head, t_redir *new_redir)
{
	t_redir	*curr;

	if (!*head)
	{
		*head = new_redir;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_redir;
}

static t_redir_type	get_redir_type(t_token_type type)
{
	if (type == TOK_LT)
		return (REDIR_IN);
	if (type == TOK_GT)
		return (REDIR_OUT);
	if (type == TOK_DGT)
		return (REDIR_APPEND);
	if (type == TOK_DLT)
		return (REDIR_HEREDOC);
	return (REDIR_IN);
}

t_redir	*parse_redirections(t_token **tokens)
{
	t_redir			*head;
	t_redir			*new_redir;
	t_redir_type	type;
	char			*file;

	head = NULL;
	while (*tokens && ((*tokens)->type == TOK_LT || (*tokens)->type == TOK_GT
			|| (*tokens)->type == TOK_DGT || (*tokens)->type == TOK_DLT))
	{
		type = get_redir_type((*tokens)->type);
		*tokens = (*tokens)->next;
		if (!*tokens || (*tokens)->type != TOK_WORD)
		{
			printf("minishell: syntax error near unexpected token\n");
			return (free_redir_list(head), NULL);
		}
		file = remove_quotes((*tokens)->token);
		new_redir = create_redir(file, type);
		free(file);
		if (!new_redir)
			return (free_redir_list(head), NULL);
		add_redir_to_list(&head, new_redir);
		*tokens = (*tokens)->next;
	}
	return (head);
}
