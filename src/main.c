/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:32:14 by muhakhan          #+#    #+#             */
/*   Updated: 2025/11/11 20:55:49 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	while (1)
	{
		char *input = readline("minishell$ ");
		if (!input)
			exit(0);
		free(input);
	}
}