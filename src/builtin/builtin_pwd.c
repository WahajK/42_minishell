/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:26:59 by okhan             #+#    #+#             */
/*   Updated: 2025/12/28 18:33:38 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(char **args)
{
	char	cwd[CWD_BUFFER_SIZE];

	if(args[1] != NULL)
	{
		fprintf(stderr, "minishell: pwd. Too many arguments!\n");
		return (1);
	}

	if (getcwd(cwd, CWD_BUFFER_SIZE) != NULL)
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
	{
		perror("pwd");
		return (1);
	}
}