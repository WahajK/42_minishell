/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:27:47 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 19:58:10 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	void	write_heredoc(char *delimiter, int fd, t_data *data, int expand)
{
	char	*line;
	char	*expanded;

	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		if (expand)
		{
			expanded = expand_variables(line, data);
			if (expanded)
			{
				ft_putendl_fd(expanded, fd);
				free(expanded);
			}
		}
		else
			ft_putendl_fd(line, fd);
		free(line);
	}
}

static	int	handle_heredoc(t_redir *redir, int id, t_data *data)
{
	int		fd;
	char	*tmp_name;
	char	*id_str;

	id_str = ft_itoa(id);
	tmp_name = ft_strjoin(".heredoc_tmp_", id_str);
	free(id_str);
	fd = open(tmp_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (free(tmp_name), -1);
	write_heredoc(redir->file, fd, data, redir->expand);
	close(fd);
	free(redir->file);
	redir->file = tmp_name;
	return (0);
}

void	prepare_heredocs(t_command *cmds, t_data *data)
{
	t_command	*curr_cmd;
	t_redir		*curr_redir;
	int			id;

	id = 0;
	curr_cmd = cmds;
	while (curr_cmd)
	{
		curr_redir = curr_cmd->redirs;
		while (curr_redir)
		{
			if (curr_redir->type == REDIR_HEREDOC)
				handle_heredoc(curr_redir, id++, data);
			curr_redir = curr_redir->next;
		}
		curr_cmd = curr_cmd->next;
	}
}

void	cleanup_heredocs(t_command *cmds)
{
	t_command	*cmd;
	t_redir		*redir;

	cmd = cmds;
	while (cmd)
	{
		redir = cmd->redirs;
		while (redir)
		{
			if (redir->type == REDIR_HEREDOC && redir->file)
				unlink(redir->file);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}
