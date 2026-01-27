/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:33 by okhan             #+#    #+#             */
/*   Updated: 2026/01/27 18:08:01 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_exit_numeric_error(char *arg)
{
	fprintf(stderr, "minishell: exit: %s: "
		"numeric argument required\n", arg);
}

int	builtin_exit(char **args, t_data *data)
{
	int		arg_count;
	long	exit_code;
	int		error;

	arg_count = 0;
	while (args[arg_count])
		arg_count++;
	if (arg_count == 1)
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
	if (arg_count > 2)
	{
		fprintf(stderr, "minishell: exit: too many arguments\n");
		return (1);
	}
	exit((int)(exit_code % 256));
	return (0);
}
