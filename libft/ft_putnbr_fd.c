/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:03:31 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/09 18:18:16 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putnbr_fd - Outputs the integer n to the given file descriptor.
 * @n: The integer to output.
 * @fd: The file descriptor on which to write.
 *
 * This function handles the special case of the minimum integer value
 * (-2147483648) and writes it directly to the file descriptor. For other
 * negative values, it writes a '-' character and then converts the number
 * to positive before processing. The function uses an array to store the
 * digits of the number in reverse order and then writes them to the file
 * descriptor in the correct order.
 */
int	ft_putnbr_fd(long long int n, int fd)
{
	char	arr[30];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (n == 0)
		return (write(fd, "0", 1));
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count++;
	}
	while (n > 9)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	arr[i++] = n + '0';
	count += i;
	while (--i >= 0)
		write(fd, &arr[i], 1);
	return (count);
}
