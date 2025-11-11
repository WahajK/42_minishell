/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:25:55 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/27 02:19:28 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_node **head, t_node **tail, t_node *new)
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
		(*tail)->prev = new;
		new->next = *tail;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}
