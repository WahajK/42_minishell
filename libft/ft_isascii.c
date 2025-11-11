/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:39:43 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:04:35 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 * @brief Checks if a character is an ASCII character.
 *
 * This function checks whether the given character is an ASCII character,
 * which means it falls within the range of 0 to 127 inclusive.
 *
 * @param chr The character to be checked.
 * @return 1 if the character is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int chr)
{
	return (chr >= 0 && chr <= 127);
}
