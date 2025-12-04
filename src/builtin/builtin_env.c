/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:43:38 by okhan             #+#    #+#             */
/*   Updated: 2025/12/04 16:16:03 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int builtin_env(t_command *cmd, t_data *data)
{
    t_env *current;

    if (cmd->args[1] != NULL)
    {
        fprintf(stderr, "minishell: env: too many arguments\n");
        return (1);
    }

    current = data->env_list; // Access the environment list through the data structure
    while (current)
    {
        if (current->value)
            printf("%s=%s\n", current->key, current->value);
        current = current->next;
    }
    return (0);
}