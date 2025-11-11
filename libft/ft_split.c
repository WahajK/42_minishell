/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:06:25 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/04 19:11:42 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees a 2D array of strings and returns NULL.
 *
 * This function takes a 2D array of strings and an index, and frees all the
 * strings from the given index down to 0, then frees the array itself.
 *
 * @param arr The 2D array of strings to be freed.
 * @param i The index from which to start freeing the strings.
 * @return Always returns NULL.
 */
static char	**destructor(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

/**
 * count_words - Counts the number of words in a string separated by a delimiter
 * @s: The input string to be split
 * @c: The delimiter character
 *
 * This function iterates through the input string and counts the number of
 * words separated by the specified delimiter character. A word is defined as
 * a sequence of characters that does not include the delimiter.
 *
 * Return: The number of words in the input string
 */
static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

/**
 * ft_split - Splits a string into an array of strings using a delimiter.
 * @s: The string to be split.
 * @c: The delimiter character.
 *
 * This function allocates memory for an array of strings, splits the input
 * string @s by the delimiter @c, and stores each substring in the array.
 * The array is terminated by a NULL pointer.
 *
 * Return: A pointer to the array of strings, or NULL if memory allocation
 * fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	len;

	i = 0;
	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			ptr[i++] = ft_substr(s - len, 0, len);
			if (!ptr[i - 1])
				return (destructor(ptr, i - 1));
		}
		else
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

// #include <stdio.h>
// int	main()
// {
// 	char **tabstr;
// 	if (!(tabstr = ft_split("", 'z')))
//         	printf("NULL");
// 	else
// 		if (!tabstr[0])
// 			printf("ok\n");
// }