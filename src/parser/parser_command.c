/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 17:38:32 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	process_arg(t_token *token, char **arg, t_data *data)
{
	char	*cleaned;
	char	*expanded;

	if (token->token[0] == '\'')
	{
		cleaned = remove_quotes(token->token);
		if (!cleaned)
			return (0);
		*arg = cleaned;
		return (1);
	}
	cleaned = remove_quotes(token->token);
	if (!cleaned)
		return (0);
	expanded = expand_variables(cleaned, data);
	free(cleaned);
	if (!expanded)
		return (0);
	*arg = expanded;
	return (1);
}

static int	fill_args(t_token **token_ptr, char **args, int count, t_data *data)
{
	int		i;

	i = 0;
	while (i < count)
	{
		if (!*token_ptr || (*token_ptr)->type != TOK_WORD)
			return (0);
		if (!process_arg(*token_ptr, &args[i], data))
			return (0);
		*token_ptr = (*token_ptr)->next;
		i++;
	}
	return (1);
}

static int	count_args(t_token *tokens)
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
	if (!fill_args(tokens, cmd->args, arg_count, data))
		return (free_command(cmd), NULL);
	cmd->args[arg_count] = NULL;
	cmd->is_builtin = is_builtin_cmd(cmd->args[0]);
	return (cmd);
}

t_command	*parse_simple_command(t_token **tokens, t_data *data)
{
	t_command	*cmd;
	t_redir		*redirs;

	if (!*tokens || (*tokens)->type == TOK_PIPE)
		return (NULL);
	cmd = create_simple_command(tokens, data);
	if (!cmd)
		return (NULL);
	redirs = parse_redirections(tokens);
	cmd->redirs = redirs;
	return (cmd);
}
