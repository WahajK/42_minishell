/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:00:00 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/24 22:57:27 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_builtin_cmd(char *cmd)
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

static int	fill_args(t_token **token_ptr, char **args, int count)
{
	int		i;
	char	*cleaned;

	i = 0;
	while (i < count)
	{
		if (!*token_ptr || (*token_ptr)->type != TOK_WORD)
			return (0);
		cleaned = remove_quotes((*token_ptr)->token);
		if (!cleaned)
			return (0);
		args[i] = cleaned;
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

static t_command	*create_simple_command(t_token **tokens)
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
	if (!fill_args(tokens, cmd->args, arg_count))
		return (free_command(cmd), NULL);
	cmd->args[arg_count] = NULL;
	cmd->is_builtin = is_builtin_cmd(cmd->args[0]);
	return (cmd);
}

t_command	*parse_simple_command(t_token **tokens)
{
	t_command	*cmd;
	t_redir		*redirs;

	if (!*tokens || (*tokens)->type == TOK_PIPE)
		return (NULL);
	cmd = create_simple_command(tokens);
	if (!cmd)
		return (NULL);
	redirs = parse_redirections(tokens);
	cmd->redirs = redirs;
	return (cmd);
}
