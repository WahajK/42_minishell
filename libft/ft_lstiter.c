/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:48:01 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/04 18:51:43 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstiter.c
 * @brief Applies a function to each element of a linked list.
 *
 * This function iterates over each element of the linked list 'lst' and applies
 * the function 'f' to the content of each element.
 *
 * @param lst The beginning of the linked list.
 * @param f The function to apply to the content of each element.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
