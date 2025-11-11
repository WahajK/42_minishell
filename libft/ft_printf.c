/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:43:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/28 16:51:41 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	char	result[33];
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		count++;
	}
	while (nbr > 0 && ++count)
	{
		result[i++] = base[nbr % 16];
		nbr = nbr / 16;
	}
	while (--i >= 0)
		write(1, &result[i], 1);
	return (count);
}

int	print_address(unsigned long addr)
{
	if (!addr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putnbr_base(addr, "0123456789abcdef") + 2);
}

int	print_modifier(va_list args, const char *format, int i)
{
	if (format[i] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format[i] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (format[i] == 'p')
		return (print_address(va_arg(args, unsigned long)));
	else if (format[i] == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format[i] == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format[i] == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1));
	else if (format[i] == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format[i] == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += print_modifier(args, format, i);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
