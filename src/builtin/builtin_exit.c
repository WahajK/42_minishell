/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:33 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:38:48 by muhakhan         ###   ########.fr       */
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

static int	process_exit_args(int argc, char **args, t_data *data)
{
	long	exit_code;
	int		error;

	if (argc == 1)
	{
		free_shell_data(data);
		exit(data->last_exit_code);
	}
	exit_code = ft_atol(args[1], &error);
	if (error || !is_numeric(args[1]))
	{
		print_exit_numeric_error(args[1]);
		free_shell_data(data);
		exit(255);
	}
	if (argc > 2)
	{
		fprintf(stderr, "minishell: exit: too many arguments\n");
		return (1);
	}
	exit((int)(exit_code % 256));
	return (0);
}

int	builtin_exit(char **args, t_data *data)
{
	int	argc;

	argc = get_arg_count(args);
	return (process_exit_args(argc, args, data));
}
