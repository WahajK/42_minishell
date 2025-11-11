/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:48:36 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/04 19:20:29 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @file ft_lstmap.c
 * @brief Applies a function to each element of a list and creates a new list.
 *
 * This function iterates through the list 'lst' and applies the function 'f'
 * to the content of each element. It creates a new list resulting from the
 * successive applications of 'f'. If the allocation of a new element fails,
 * the 'del' function is used to delete the content and the entire new list is
 * cleared.
 *
 * @param lst The address of a pointer to the first element of the list.
 * @param f The function to apply to the content of each element.
 * @param del The function to delete the content of an element if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_list;
	t_list		*new_element;
	void		*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_element = ft_lstnew(content);
		if (!new_element)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
