/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:41:41 by muhakhan          #+#    #+#             */
/*   Updated: 2025/05/22 23:11:45 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

/**
 * set_line - Reads from a file descriptor and appends to the line until a 
 *            newline character is found or end of file is reached.
 * @fd: The file descriptor to read from.
 * @buffer: The buffer to store read data.
 * @line: The line to append read data to.
 *
 * This function reads from the given file descriptor into the buffer and 
 * appends the buffer content to the line until a newline character is found 
 * or the end of the file is reached. If the line already contains a newline 
 * character, the function returns immediately. The buffer is freed before 
 * returning.
 */
static void	set_line(int fd, char *buffer, char **line)
{
	int		i;
	char	*temp;

	if (!*line || !ft_strchr(*line, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			return (free(buffer));
		while (i > 0)
		{
			buffer[i] = '\0';
			if (!*line)
				*line = ft_substr(buffer, 0, i);
			else
			{
				temp = *line;
				*line = ft_strjoin(*line, buffer);
				free(temp);
			}
			if (ft_strchr(*line, '\n'))
				break ;
			i = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

/**
 * get_line - Extracts a line from the given string and updates the string.
 * @line: Double pointer to the string from which the line is extracted.
 *
 * This function extracts a line from the given string up to and including
 * the first newline character. If there is no newline character, it returns
 * the entire string. The extracted line is returned, and the original string
 * is updated to remove the extracted part. If the input string is NULL, the
 * function returns NULL.
 *
 * Return: A pointer to the extracted line, or NULL if the input string is NULL.
 */
static char	*get_line(char **line)
{
	int		i;
	int		j;
	char	*ret;
	char	*temp;

	if (!*line)
		return (0);
	if (!ft_strchr(*line, '\n'))
	{
		ret = ft_substr(*line, 0, ft_strlen(*line));
		free (*line);
		*line = 0;
		return (ret);
	}
	i = ft_strlen(*line);
	j = ft_strlen(ft_strchr(*line, '\n'));
	ret = ft_substr(*line, 0, i - j + 1);
	temp = *line;
	*line = ft_substr(ft_strchr(*line, '\n'), 1, j - 1);
	free(temp);
	return (ret);
}

/**
 * get_next_line - Reads a line from a file descriptor.
 * @fd: The file descriptor to read from.
 *
 * This function reads a line from the given file descriptor and returns it as
 * a string. It uses a static variable to store the remaining part of the line
 * between function calls. The function allocates memory for the buffer and
 * checks for errors such as invalid file descriptor or read errors.
 *
 * Return: A string containing the next line from the file descriptor, or NULL
 * if an error occurs or if the end of the file is reached.
 */
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (0);
	}
	set_line(fd, buffer, &line);
	return (get_line(&line));
}
