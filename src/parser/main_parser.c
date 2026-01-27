/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:34:57 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/24 22:48:42 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	strip_newline(char *str)
{
	char	*newline;

	if (!str)
		return ;
	newline = str;
	while (*newline)
	{
		if (*newline == '\n')
		{
			*newline = '\0';
			return ;
		}
		newline++;
	}
}

int	init_history(void)
{
	int		fd;
	char	*line;

	if (access(HISTORY_FILE, R_OK) != 0)
		return (0);
	fd = open(HISTORY_FILE, O_RDONLY);
	if (fd < 0)
		return (printf("minishell: could not open history file\n"), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		strip_newline(line);
		if (*line)
			add_history(line);
		free(line);
	}
	close(fd);
	return (0);
}

void	save_command_to_history(const char *command)
{
	int		fd;
	size_t	len;

	if (!command || *command == '\0')
		return ;
	fd = open(HISTORY_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
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

	(void)data;
	commands = parse_input(input);
	if (!commands)
		return ;
	printf("Parsed successfully!\n");
	printf("Command: %s\n", commands->args[0]);
	if (commands->args[1])
		printf("Arg1: %s\n", commands->args[1]);
	if (commands->redirs)
		printf("Has redirections\n");
	if (commands->next)
		printf("Has pipeline\n");
	free_command_list(commands);
}

int	parse_loop(void)
{
	char	*input;
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
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
			process_input(input, &data);
		}
		free(input);
	}
	rl_clear_history();
	return (0);
}
