/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:10 by okhan             #+#    #+#             */
/*   Updated: 2026/01/24 18:12:39 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_redir_fd(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == TOK_LT || redir->type == TOK_DLT)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == TOK_GT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == TOK_DGT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	apply_redirections(t_redir *redirs)
{
	int	fd;
	int	target_fd;

	while (redirs)
	{
		fd = get_redir_fd(redirs);
		if (fd < 0)
		{
			perror(redirs->file);
			return (-1);
		}
		if (redirs->type == TOK_LT || redirs->type == TOK_DLT)
			target_fd = STDIN_FILENO;
		else
			target_fd = STDOUT_FILENO;
		if (dup2(fd, target_fd) < 0)
			return (close(fd), -1);
		close(fd);
		redirs = redirs->next;
	}
	return (0);
}
