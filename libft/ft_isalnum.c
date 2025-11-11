/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:37:32 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:03:48 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_isalnum - checks if the character is alphanumeric
 * @chr: the character to be checked
 *
 * This function checks if the given character is an alphanumeric character,
 * which means it is either a letter (uppercase or lowercase) or a digit.
 *
 * Return: 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int chr)
{
	return ((chr >= 'A' && chr <= 'Z')
		|| (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'));
}
