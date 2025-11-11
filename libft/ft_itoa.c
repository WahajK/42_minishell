/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:53:23 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/04 19:05:36 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the number of digits in an integer.
 *
 * This function takes an integer as input and returns the number of digits
 * required to represent the integer, including the sign if the number is
 * negative.
 *
 * @param n The integer whose length is to be calculated.
 * @return The number of digits in the integer.
 */
static int	ft_numlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= 10;
	return (count);
}

/**
 * ft_itoa - Converts an integer to a null-terminated string.
 * @n: The integer to be converted.
 *
 * This function allocates memory for a string representation of the integer
 * and returns a pointer to it. The caller is responsible for freeing the
 * allocated memory. If memory allocation fails, the function returns NULL.
 *
 * Return: A pointer to the string representation of the integer, or NULL if
 * memory allocation fails.
 */
char	*ft_itoa(int n)
{
	int			len;
	char		*ret;
	const char	*digits = "0123456789";

	len = ft_numlen(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
}
