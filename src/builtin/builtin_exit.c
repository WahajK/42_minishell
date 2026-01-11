/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:33 by okhan             #+#    #+#             */
/*   Updated: 2025/12/28 18:36:15 by okhan            ###   ########.fr       */
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

	// optional sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// convert digits
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}


/**
 * @brief Implements the 'exit' built-in command.
 * 
 * @param cmd The command structure containing arguments.
 * @param data The main shell data structure.
 * @return int Returns 1 if 'too many arguments' error occurs, otherwise exits.
 */
int	builtin_exit(char **args, t_data *data)
{
	int			arg_count;
	long long	exit_code;

	arg_count = 0;
	while (args[arg_count])
		arg_count++;

	// Scenario 1: No arguments
	if (arg_count == 1)
	{
		free_shell_data(data);
		exit(data->last_exit_code);
	}

	// Scenario 2 & 3: Arguments provided
	if (!is_numeric(args[1]))
	{
		fprintf(stderr, "minishell: exit: %s: numeric argument required\n", args[1]);
		free_shell_data(data);
		exit(255);
	}

	// Check for 'too many arguments' (first argument is numeric)
	if (arg_count > 2)
	{
		fprintf(stderr, "minishell: exit: too many arguments\n");
		return (1); // Return 1, DO NOT EXIT
	}

	// Scenario 2: One valid numeric argument
	// Use ft_atol (or strtol) for conversion
	exit_code = ft_atol(args[1]); // Assuming ft_atol is in your libft
	
	free_shell_data(data);
	// Exit status is the lower 8 bits (modulo 256)
	exit((int)(exit_code % 256));
	
	return (0); // Should not be reached
}