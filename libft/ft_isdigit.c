/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:19:15 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:04:52 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isdigit.c
 * @brief Checks if the given character is a digit.
 *
 * This function checks if the input character is a digit (0-9).
 *
 * @param chr The character to be checked.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int chr)
{
	return (chr >= '0' && chr <= '9');
}
