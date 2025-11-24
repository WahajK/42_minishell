/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:34:57 by muhakhan          #+#    #+#             */
/*   Updated: 2025/11/24 17:35:39 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	skip_whitespaces(char *input)
{
	int	i;

	i = 0;
	while (*input == ' ')
	{
		input++;
		i++;
	}
	return (i);
}

t_token	*lexer(char *input)
{
	int		i;
	t_token *head;

	i = 0;
	head = NULL;
	while (input[i])
	{
		i = skip_whitespaces(input[i]);
		if (is_operator(&head, input))
			i = handle_opeartor(input[i]);
		if (is_word(&head, input))
			i = handle_word(input[i]);
	}
	return (head);
}

void	parse_loop(void)
{
	while (1)
	{
		char *input = readline("minishell$ ");
		printf("Input: %s\n", input);
		lexer(input);
		if (!input)
			exit(0);
		free(input);
	}
}