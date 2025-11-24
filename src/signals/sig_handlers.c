/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:17 by muhakhan          #+#    #+#             */
/*   Updated: 2025/11/24 17:42:44 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_sigint(void *context)
{
	printf("\nMeow");
	return ;
}

void	handle_sigquit(void *context)
{
	printf("\nMeow");
	return ;
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGINT)
		handle_sigint(NULL);
	else if (signum == SIGQUIT)
		handle_sigquit(NULL);
}
