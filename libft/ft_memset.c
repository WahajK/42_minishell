/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:35:53 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:07:53 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with 
 *        the constant byte c.
 * 
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to be set. It is passed as an int and converted 
 *          to unsigned char.
 * @param n Number of bytes to be set to the value.
 * @return void* Pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + (i++)) = (unsigned char)c;
	return (s);
}
