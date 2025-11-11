/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:59:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:16:19 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src 
 * to dest, NUL-terminating the result.
 * 
 * @param dest The destination buffer where the content is to be copied.
 * @param src The source string from which the content is to be copied.
 * @param size The size of the destination buffer.
 * 
 * @return The total length of the string it tried to create, i.e., the length 
 * of src.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
	char dest[100];
	char src[] = "Meowssssss";
	printf("%u\n", strlcpy(dest,src,11));
	printf("%u\n", ft_strlcpy(dest, src, 11));
	printf("Destination: %s\n", dest);
	return 0;
}
*/
