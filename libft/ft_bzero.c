/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:51:58 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:02:42 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero - Sets the first n bytes of the area starting at s to zero 
 * (bytes containing '\0').
 * @s: Pointer to the memory area to be zeroed.
 * @n: Number of bytes to be set to zero.
 *
 * This function writes n zeroed bytes to the string s. If n is zero, 
 * ft_bzero() does nothing.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + (i++)) = 0;
}
