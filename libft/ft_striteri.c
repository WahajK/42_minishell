/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:08:35 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/03 20:10:20 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_striteri - Applies the function f to each character of the string s,
 *               passing its index as the first argument.
 * @s: The string to iterate over.
 * @f: The function to apply to each character of s.
 *
 * Description: This function iterates over the string s and applies the
 *              function f to each character, passing the character's index
 *              as the first argument to f. If s is NULL, the function does
 *              nothing.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}
