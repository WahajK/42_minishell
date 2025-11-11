/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:24:55 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/27 02:18:46 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(int data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
		return (0);
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
