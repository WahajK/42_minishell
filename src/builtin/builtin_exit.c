/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:33 by okhan             #+#    #+#             */
/*   Updated: 2026/01/28 17:31:57 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_exit_numeric_error(char *arg)
{
	fprintf(stderr, "minishell: exit: %s: "
		"numeric argument required\n", arg);
}

static int	get_arg_count(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static void	cleanup_and_exit(t_data *data, int exit_code)
{
	if (data->current_commands)
		free_command_list(data->current_commands);
	free_shell_data(data);
	exit(exit_code);
}

static int	process_exit_args(int argc, char **args, t_data *data)
{
	long	exit_code;
	int		error;

	error = 0;
	if (argc == 1)
		cleanup_and_exit(data, data->last_exit_code);
	exit_code = ft_atol(args[1], &error);
	if (error || !is_numeric(args[1]))
	{
		print_exit_numeric_error(args[1]);
		cleanup_and_exit(data, 2);
	}
	if (argc > 2)
	{
		fprintf(stderr, "minishell: exit: too many arguments\n");
		return (1);
	}
	cleanup_and_exit(data, (unsigned char)exit_code);
	return (0);
}

int	builtin_exit(char **args, t_data *data)
{
	int	argc;

	argc = get_arg_count(args);
	return (process_exit_args(argc, args, data));
}
