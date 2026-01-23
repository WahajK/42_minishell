/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:33 by okhan             #+#    #+#             */
/*   Updated: 2026/01/23 17:11:22 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static long	ft_atol(char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static	void	print_exit_numeric_error(char *arg)
{
	fprintf(stderr, "minishell: exit: %s: "
		"numeric argument required\n", arg);
}

int	builtin_exit(char **args, t_data *data)
{
	int			arg_count;
	long long	exit_code;

	arg_count = 0;
	while (args[arg_count])
		arg_count++;
	if (arg_count == 1)
	{
		free_shell_data(data);
		exit(data->last_exit_code);
	}
	if (!is_numeric(args[1]))
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
	exit_code = ft_atol(args[1]);
	exit((int)(exit_code % 256));
	return (0);
}
