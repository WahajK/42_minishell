/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:10 by okhan             #+#    #+#             */
/*   Updated: 2026/01/23 18:23:09 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include "../../include/minishell.h"

static int	open_redir_file(t_redir *redir, int *target_fd)
{
	int	fd;

	if (redir->type == TOK_LT)
	{
		fd = open(redir->file, O_RDONLY);
		*target_fd = STDIN_FILENO;
	}
	else if (redir->type == TOK_GT)
	{
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		*target_fd = STDOUT_FILENO;
	}
	else if (redir->type == TOK_DGT)
	{
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		*target_fd = STDOUT_FILENO;
	}
	else
		fd = -1;
	return (fd);
}

int	apply_redirections(t_redir *redirs)
{
	int	fd;
	int	target_fd;

	while (redirs)
	{
		fd = open_redir_file(redirs, &target_fd);
		if (fd < 0)
			return (perror(redirs->file), -1);
		if (dup2(fd, target_fd) < 0)
			return (close(fd), -1);
		close(fd);
		redirs = redirs->next;
	}
	return (0);
}
