/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:50:32 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/05 19:12:12 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_memcmp.c
 * @brief Compares byte string s1 against byte string s2.
 *
 * The ft_memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * @param s1 Pointer to the first byte string.
 * @param s2 Pointer to the second byte string.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first
 * n bytes of s1 is found, respectively, to be less than, to match, or be
 * greater than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
		{
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		}
		i++;
	}
	i--;
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
