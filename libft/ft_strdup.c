/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:58:33 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:10:09 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies the string pointed to by src to dest.
 *
 * This function copies the string pointed to by src, including the terminating
 * null byte ('\0'), to the buffer pointed to by dest. The strings should not
 * overlap, and the destination string dest must be large enough to receive the
 * copy.
 *
 * @param dest A pointer to the destination array where the content is to be
 * copied.
 * @param src A pointer to the null-terminated string to be copied.
 * @return A pointer to the destination string dest.
 */
static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * @file ft_strdup.c
 * @brief Duplicates a string.
 *
 * This function allocates sufficient memory for a copy of the string s,
 * does the copy, and returns a pointer to it. The pointer may subsequently
 * be used as an argument to the function free.
 *
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string, or NULL if insufficient memory
 *         was available.
 */
char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (*(char *)s == '\0')
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(ft_strlen((char *)s) + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, (char *)s);
	return (ptr);
}
