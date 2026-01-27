/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:17:10 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:22:49 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	get_redir_fd(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == REDIR_IN || redir->type == REDIR_HEREDOC)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == REDIR_OUT)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == REDIR_APPEND)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	apply_redirections(t_redir *redirs)
{
	int	fd;
	int	target_fd;

	if (!redirs)
		return (0);
	while (redirs)
	{
		fd = get_redir_fd(redirs);
		if (fd < 0)
		{
			perror(redirs->file);
			return (-1);
		}
		if (redirs->type == REDIR_IN || redirs->type == REDIR_HEREDOC)
			target_fd = STDIN_FILENO;
		else
			target_fd = STDOUT_FILENO;
		if (dup2(fd, target_fd) < 0)
		{
			perror("dup2");
			close(fd);
			return (-1);
		}
		close(fd);
		redirs = redirs->next;
	}
	return (0);
}
