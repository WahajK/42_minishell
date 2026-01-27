/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:34:57 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/27 20:38:36 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_history_path(void)
{
	char	*home;
	char	*tmp;
	char	*path;

	home = getenv("HOME");
	if (!home)
		return (ft_strdup(HISTORY_FILE));
	tmp = ft_strjoin(home, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, HISTORY_FILE);
	free(tmp);
	return (path);
}

static int	read_history_lines(int fd)
{
	char	*line;
	char	*nl;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		nl = ft_strchr(line, '\n');
		if (nl)
			*nl = '\0';
		if (*line)
			add_history(line);
		free(line);
	}
	return (0);
}

int	init_history(void)
{
	int		fd;
	char	*path;

	path = get_history_path();
	if (!path)
		return (printf("minishell: could not resolve history path\n"), -1);
	if (access(path, R_OK) != 0)
		return (free(path), 0);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
		return (printf("minishell: could not open history file\n"), -1);
	read_history_lines(fd);
	close(fd);
	return (0);
}

void	save_command_to_history(const char *command)
{
	int		fd;
	size_t	len;
	char	*path;

	if (!command || *command == '\0')
		return ;
	path = get_history_path();
	if (!path)
	{
		printf("minishell: could not resolve history path\n");
		return ;
	}
	fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(path);
	if (fd < 0)
	{
		printf("minishell: could not write to history file\n");
		return ;
	}
	len = ft_strlen(command);
	write(fd, command, len);
	write(fd, "\n", 1);
	close(fd);
}

static void	process_input(char *input, t_data *data)
{
	t_command	*commands;
	int			status;

	if (parse_input(input, data, &commands) != 0)
	{
		data->last_exit_code = 1;
		return ;
	}
	if (!commands)
		return ;
	data->current_commands = commands;
	prepare_heredocs(commands, data);
	if (commands->next)
		status = execute_pipeline(commands, data);
	else
		status = execute_command(commands, data);
	data->last_exit_code = status;
	cleanup_heredocs(commands);
	free_command_list(commands);
	data->current_commands = NULL;
}

int	parse_loop(t_data *data)
{
	char	*input;

	if (init_history() != 0)
		return (1);
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
		{
			add_history(input);
			save_command_to_history(input);
			process_input(input, data);
		}
		free(input);
	}
	rl_clear_history();
	return (0);
}
