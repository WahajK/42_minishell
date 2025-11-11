/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:51:46 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:13:04 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates up to n characters from the given string.
 *
 * This function allocates memory and duplicates up to n characters from the 
 * string s. The resulting string is null-terminated.
 *
 * @param s The string to duplicate.
 * @param n The maximum number of characters to duplicate.
 * @return A pointer to the newly allocated string, or NULL if allocation fails.
 */
static char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}

/**
 * ft_is_in_set - Checks if a character is part of a given set of characters.
 * @c: The character to check.
 * @set: The set of characters to check against.
 *
 * Return: 1 if the character is in the set, 0 otherwise.
 */
static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/**
 * ft_strtrim - Trims the characters from the beginning and end of a string
 *              that are present in the given set.
 * @s1: The original string to be trimmed.
 * @set: The set of characters to be trimmed from the string.
 *
 * Return: A new string with the characters from the set trimmed from the
 *         beginning and end. If memory allocation fails, returns NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (end > start && ft_is_in_set(s1[end], set))
		end--;
	ptr = ft_strndup(&s1[start], end - start + 1);
	return (ptr);
}
