/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:24:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:10:30 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strjoin - Allocates and returns a new string, which is the result of 
 * the concatenation of 's1' and 's2'.
 * @s1: The prefix string.
 * @s2: The suffix string.
 *
 * Return: The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j++] = s2[i];
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
