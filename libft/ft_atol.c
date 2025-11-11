/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:01 by muhakhan          #+#    #+#             */
/*   Updated: 2025/04/01 22:19:00 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long	ft_atol(const char *str, int *error)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++ - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			*error = -1;
	}
	return (result * sign);
}
