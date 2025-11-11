/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:08:31 by muhakhan          #+#    #+#             */
/*   Updated: 2025/05/22 23:05:33 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies up to n - 1 characters from the string src to dest, 
 *        null-terminating the result if n is not 0.
 * 
 * @param dest The destination buffer where the content is to be copied.
 * @param src The source string to be copied.
 * @param n The maximum number of characters to be copied from src.
 * 
 * @return A pointer to the destination string dest.
 */
static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * @brief Duplicates up to n characters from the given string.
 *
 * This function allocates memory and duplicates up to n characters from the
 * input string 's' into the newly allocated memory. The duplicated string
 * is null-terminated.
 *
 * @param s The input string to duplicate.
 * @param n The maximum number of characters to duplicate.
 * @return A pointer to the newly allocated string, or NULL if allocation fails.
 */
static char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strncpy(ptr, s, n + 1);
	return (ptr);
}

/**
 * ft_substr - Allocates and returns a substring from the string 's'.
 * @s: The string from which to create the substring.
 * @start: The start index of the substring in the string 's'.
 * @len: The maximum length of the substring.
 *
 * Return: The substring. NULL if the allocation fails or if 's' is NULL.
 *
 * Description: This function allocates memory for a substring of 's' starting
 * from index 'start' and of maximum length 'len'. If 'start' is greater than
 * the length of 's' or 'len' is 0, it returns an empty string. If memory
 * allocation fails, it returns NULL.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (NULL);
	else
	{
		s += start;
		if (len > ft_strlen(s))
			len = ft_strlen(s);
		ptr = ft_strndup(s, len);
	}
	return (ptr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char *result;

// 	// Test case 1: Normal case
// 	result = ft_substr("Hello, World!", 7, 5);
// 	printf("Test 1: %s\n", result); // Expected: "World"
// 	free(result);

// 	// Test case 2: Start index out of bounds
// 	result = ft_substr("Hello, World!", 20, 5);
// 	printf("Test 2: %s\n", result); // Expected: ""
// 	free(result);

// 	// Test case 3: Length exceeds string length
// 	result = ft_substr("Hello", 1, 10);
// 	printf("Test 3: %s\n", result); // Expected: "ello"
// 	free(result);

// 	// Test case 4: Start index is 0
// 	result = ft_substr("Hello", 0, 3);
// 	printf("Test 4: %s\n", result); // Expected: "Hel"
// 	free(result);

// 	// Test case 5: Empty string
// 	result = ft_substr("", 0, 5);
// 	printf("Test 5: %s\n", result); // Expected: ""
// 	free(result);

// 	return (0);
// }