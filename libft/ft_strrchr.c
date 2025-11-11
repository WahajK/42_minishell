/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:43:34 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:12:32 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * ft_strrchr - Locate the last occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * This function searches for the last occurrence of the character @c
 * (converted to an unsigned char) in the string pointed to by @s.
 * The terminating null character is considered part of the string.
 *
 * Return: A pointer to the last occurrence of the character @c in the
 * string @s, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%s", ft_strrchr("My namen is Meow", '\0'));
// }