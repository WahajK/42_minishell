/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:27:07 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:09:44 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * ft_strchr - Locate character in string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * This function locates the first occurrence of the character @c (converted to
 * an unsigned char) in the string pointed to by @s. The terminating null byte
 * is considered part of the string, so that if @c is '\0', the function will
 * return a pointer to the terminator.
 *
 * Return: A pointer to the first occurrence of the character @c in the string
 * @s, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
// #include <stdio.h>
// int	main()
// {
// 	printf("%s", ft_strchr("My name is Meow", 'n'));
// 	printf("%s", ft_strchr("teste", 'e'));
// }