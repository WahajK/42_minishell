/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:45:32 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:14:08 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 * @brief Converts a lowercase letter to uppercase.
 *
 * This function takes an integer representing a character as input and 
 * converts it to its uppercase equivalent if it is a lowercase letter.
 * If the character is not a lowercase letter, it is returned unchanged.
 *
 * @param ch The character to be converted.
 * @return The uppercase equivalent of the character if it is lowercase,
 *         otherwise the character itself.
 */
int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%c",ft_toupper(-1));
// }