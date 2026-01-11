/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:24:20 by okhan             #+#    #+#             */
/*   Updated: 2025/12/28 18:11:40 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char *check_path_segment(char *dir, char *cmd)
{
	char *path;
	char *tmp;

	// 1. Construct the full path: dir + "/" + cmd
	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!path)
		return (NULL);
	// 2. Check if the file exists and is executable (X_OK)	
	if (access(path, X_OK)== 0)
		return (path);
	// 3. If not found, free the path and return NULL
	free(path);
	return (NULL);
}

char *find_commadnd_path(char *cmd, t_data *data)
{
	char	*path_env;
	char	**dirs;
	char	*full_path;
	int		i;

	if (ft_strchr(cmd, '/') != NULL && access (cmd, X_OK) == 0)
		return(ft_strdup(cmd));
	path_env = get_env_value(data ,"PATH");
	if (!path_env)
		return (NULL);
	dirs = ft_split(path_env, ':');
	if (!dirs)
		return (NULL);
	i = 0;
	full_path = NULL;
	while (dirs[i] != NULL)
	{
		full_path = check_path_segment(dirs[i], cmd);
		if (full_path)
			break;
		i++;
	}
	ft_free_split(dirs);
	return (full_path);
}