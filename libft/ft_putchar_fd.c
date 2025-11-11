/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 01:24:53 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/09 00:33:11 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_putchar_fd.c
 * @brief Outputs the character 'c' to the given file descriptor.
 *
 * This function writes the character 'c' to the file descriptor specified
 * by 'fd'. It uses the write system call to perform the output operation.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
