/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:09:07 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:11:26 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strmapi - Applies a function to each character of a string.
 * @s: The input string.
 * @f: The function to apply to each character. It takes an unsigned int
 *     as the index and a char as the character, and returns a char.
 *
 * Return: A new string with the function applied to each character.
 *         Returns NULL if memory allocation fails or if the input string
 *         is NULL.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (0);
	ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		++i;
	}
	ret[i] = 0;
	return (ret);
}
