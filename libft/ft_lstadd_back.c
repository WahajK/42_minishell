/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:28:55 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/27 02:17:14 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the element 'new' at the end of the list.
 * 
 * This function traverses the list to find the last element and adds the 
 * new element at the end. If the list is empty, the new element becomes 
 * the first element of the list.
 * 
 * @param lst The address of a pointer to the first element of the list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_back(t_node **head, t_node **tail, t_node *new)
{
	if (!new)
		return ;
	if (!(*tail) && !(*head))
	{
		*head = new;
		*tail = new;
	}
	else if (!(*head)->next)
	{
		(*head)->next = new;
		new->prev = *head;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
	}
}
