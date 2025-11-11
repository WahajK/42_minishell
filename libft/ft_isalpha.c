/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:10:28 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:04:07 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isalpha - checks if the given character is an alphabetic letter.
 * @chr: The character to be checked.
 *
 * Return: 1 if the character is an alphabetic letter, 0 otherwise.
 */
int	ft_isalpha(int chr)
{
	return ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z'));
}
