/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:20:35 by muhakhan          #+#    #+#             */
/*   Updated: 2025/05/29 19:15:31 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * ft_strlen - Calculates the length of a string.
 * @s: The string whose length is to be calculated.
 *
 * Return: The number of characters in the string, excluding the null byte.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
