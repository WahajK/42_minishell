/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:34:57 by muhakhan          #+#    #+#             */
/*   Updated: 2025/11/24 18:06:05 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*skip_whitespaces(char *input)
{
	while (*input == ' ')
		input++;
	return (input);
}

int	is_EOF(t_token *token_head, char *input)
{
	if (*input == EOF)
		return (1);
	return (0);
}

int	is_operator(t_token *token_head, char *input)
{
	return (0);
}

t_token	*lexer(char *input)
{
	int		i;
	t_token	*head;

	i = 0;
	head = NULL;
	while (input[i])
	{
		input = skip_whitespaces(&input[i]);
		// if (is_operator(&head, input))
		// 	input = handle_opeartor(input[i]);
		// if (is_word(&head, input))
		// 	input = handle_word(input[i]);
		i++;
	}
	return (head);
}

void	parse_loop(void)
{
	char	*input;

	while (1)
	{
		input = readline("minishell$ ");
		printf("Input: %s\n", input);
		lexer(input);
		if (!input)
			exit(0);
		free(input);
	}
}
