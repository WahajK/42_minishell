/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:24:26 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:04:51 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isprint - Checks if a character is printable.
 * @chr: The character to be checked.
 *
 * Return: 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int chr)
{
	return (chr >= 32 && chr <= 126);
}
