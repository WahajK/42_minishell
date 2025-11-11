/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:31:24 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:16:07 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcat - Concatenates two strings ensuring null-termination.
 * @dest: The destination string to which the source string is appended.
 * @src: The source string to be appended to the destination string.
 * @size: The total size of the destination buffer.
 *
 * This function appends the null-terminated string src to the end of dest.
 * It will append at most size - strlen(dest) - 1 bytes, null-terminating
 * the result. If the size is less than or equal to the length of dest,
 * it returns size + strlen(src). Otherwise, it returns the length of the
 * string it tried to create, i.e., the initial length of dest plus the
 * length of src.
 *
 * Return: The total length of the string it tried to create.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	j = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	while (src[j] && j < size - dest_len - 1)
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char dest[20];
// 	size_t result;
// 	memset(dest, 'r', 15);
// 	result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	printf("Resulting string: %s\n", dest);
// 	printf("Total length: %u\n", result);
// 	return 0;
// }