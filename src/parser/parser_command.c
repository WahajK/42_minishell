/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/29 00:17:21 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	process_arg(t_token *token, char **arg, t_data *data)
{
	char	*expanded;

	expanded = expand_variables(token->token, data);
	if (!expanded)
		return (0);
	*arg = expanded;
	return (1);
}

static int	fill_args(t_token **token_ptr, char **args, int count, t_data *data)
{
	int		i;

	i = 0;
	while (i < count && *token_ptr)
	{
		if (is_redir_token(*token_ptr))
		{
			*token_ptr = (*token_ptr)->next;
			if (*token_ptr && (*token_ptr)->type == TOK_WORD)
				*token_ptr = (*token_ptr)->next;
		}
		else if ((*token_ptr)->type == TOK_WORD)
		{
			if (!process_arg(*token_ptr, &args[i], data))
				return (0);
			*token_ptr = (*token_ptr)->next;
			i++;
		}
		else
			break ;
	}
	return (1);
}

static int	count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && (tokens->type == TOK_WORD || is_redir_token(tokens)))
	{
		if (tokens->type == TOK_WORD)
		{
			count++;
			tokens = tokens->next;
		}
		else
		{
			tokens = tokens->next;
			if (tokens && tokens->type == TOK_WORD)
				tokens = tokens->next;
		}
	}
	return (count);
}

static t_command	*create_simple_command(t_token **tokens, t_data *data)
{
	t_command	*cmd;
	int			arg_count;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	cmd->exit_status = 0;
	arg_count = count_args(*tokens);
	cmd->args = malloc(sizeof(char *) * (arg_count + 1));
	if (!cmd->args)
		return (free(cmd), NULL);
	if (arg_count > 0 && !fill_args(tokens, cmd->args, arg_count, data))
		return (free_command(cmd), NULL);
	cmd->args[arg_count] = NULL;
	if (arg_count > 0)
		cmd->is_builtin = is_builtin_cmd(cmd->args[0]);
	else
		cmd->is_builtin = 0;
	return (cmd);
}

t_command	*parse_simple_command(t_token **tokens, t_data *data)
{
	t_command	*cmd;
	t_redir		*redirs;
	t_token		*token_start;

	if (!*tokens || (*tokens)->type == TOK_PIPE || (*tokens)->type == TOK_EOF)
		return (NULL);
	token_start = *tokens;
	cmd = create_simple_command(tokens, data);
	if (!cmd)
		return (NULL);
	*tokens = token_start;
	redirs = parse_redirections(tokens);
	cmd->redirs = redirs;
	return (cmd);
}
