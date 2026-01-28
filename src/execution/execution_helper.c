/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:45:13 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/28 16:46:01 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	setup_child_fds(t_command *cmd, t_pipe_ctx *ctx)
{
	if (ctx->prev_fd != -1)
	{
		dup2(ctx->prev_fd, STDIN_FILENO);
		close(ctx->prev_fd);
	}
	if (cmd->next)
	{
		close(ctx->pipe_fds[0]);
		dup2(ctx->pipe_fds[1], STDOUT_FILENO);
		close(ctx->pipe_fds[1]);
	}
}
