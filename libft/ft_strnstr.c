/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:31:16 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:12:13 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Locates the first occurrence of the null-terminated string `little`
 *        in the string `big`, where not more than `len` characters are
 *        searched.
 * 
 * @param big The string to be searched.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search.
 * 
 * @return If `little` is an empty string, `big` is returned; if `little`
 *         occurs nowhere in `big`, NULL is returned; otherwise a pointer
 *         to the first character of the first occurrence of `little` is
 *         returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < len)
			{
				if (!little[j + 1])
					return ((char *) &big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
