/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:36:53 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:07:07 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the 
 *        first instance of c.
 * 
 * @param s The pointer to the memory area to be scanned.
 * @param c The value to be located. The value is passed as an int, but it is 
 *          internally converted to an unsigned char.
 * @param n The number of bytes to be scanned.
 * 
 * @return A pointer to the matching byte or NULL if the character does not 
 *         occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((void *)s + i));
		i++;
	}
	return (NULL);
}
