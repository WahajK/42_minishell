/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:30:01 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/27 02:18:23 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **head, t_node **tail)
{
	if (!head || !*head)
		return ;
	ft_lstclear(&(*head)->next, tail);
	ft_lstdelone(*head);
	*head = NULL;
	*tail = NULL;
}
