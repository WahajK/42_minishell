/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:45:32 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:13:45 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @brief Converts an uppercase letter to its lowercase equivalent.
 *
 * This function takes an integer representing a character as input and 
 * returns its lowercase equivalent if it is an uppercase letter. If the 
 * character is not an uppercase letter, it returns the character unchanged.
 *
 * @param ch The character to be converted.
 * @return The lowercase equivalent of the character if it is uppercase, 
 *         otherwise the character itself.
 */
int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}
/*
int	main(void)
{
	char arr[] = "Meow";
	printf("%s", ft_strupcase(arr));
}*/
