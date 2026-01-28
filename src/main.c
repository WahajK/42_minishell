/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:32:14 by muhakhan          #+#    #+#             */
/*   Updated: 2026/01/27 18:08:19 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	ft_memset(&data, 0, sizeof(t_data));
	data.env_list = init_env(envp);
	data.last_exit_code = 0;
	data.working_dir = getcwd(NULL, 0);
	if (!data.env_list)
	{
		ft_putstr_fd("minishell: failed to initialize environment\n", 2);
		return (1);
	}
	init_signals();
	parse_loop(&data);
	free_shell_data(&data);
	return (0);
}
