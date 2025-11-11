/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:27:27 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:07:45 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memmove.c
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * The memory areas may overlap: copying takes place as though the bytes
 * in src are first copied into a temporary array that does not overlap
 * src or dest, and the bytes are then copied from the temporary array
 * to dest.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area (dest).
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = dest;
	if (dest == src || n == 0)
		return (temp);
	if (dest < src)
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(unsigned char *)(--dest) = *(unsigned char *)(--src);
	}
	return (temp);
}
