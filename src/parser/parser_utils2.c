/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:47:05 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 17:25:16 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static void	process_quoted_section(char *str, int *i, char *result, int *j)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != quote)
		result[(*j)++] = str[(*i)++];
	if (str[*i] == quote)
		(*i)++;
}

char	*remove_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;

	if (!str)
		return (ft_strdup(str));
	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			process_quoted_section(str, &i, result, &j);
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

int	is_redir_token(t_token *tok)
{
	if (!tok)
		return (0);
	return (tok->type == TOK_LT || tok->type == TOK_GT
		|| tok->type == TOK_DGT || tok->type == TOK_DLT);
}

int	consume_one_redir(t_token **tokens, t_redir **head)
{
	t_redir_type	type;
	t_redir			*new_redir;
	char			*file;
	int				expand;

	type = get_redir_type((*tokens)->type);
	*tokens = (*tokens)->next;
	if (!*tokens || (*tokens)->type != TOK_WORD)
		return (printf("minishell: syntax error near unexpected token\n"),
			-1);
	expand = ((*tokens)->token[0] != '\'' && (*tokens)->token[0] != '"');
	file = remove_quotes((*tokens)->token);
	new_redir = create_redir(file, type, expand);
	free(file);
	if (!new_redir)
		return (-1);
	add_redir_to_list(head, new_redir);
	*tokens = (*tokens)->next;
	return (0);
}
