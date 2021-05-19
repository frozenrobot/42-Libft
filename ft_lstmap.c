/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:58:13 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/19 21:20:59 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft2_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		(*del)((*lst)->content);
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
}

static void	ft2_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
	else
		*lst = new;
}

t_list	*ft2_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_elem = ft2_lstnew((*f)(lst->content));
	if (!new_elem)
		return (NULL);
	new_list = new_elem;
	while (lst->next)
	{
		lst = lst->next;
		new_elem = ft2_lstnew((*f)(lst->content));
		if (!new_elem)
			ft2_lstclear(&new_list, del);
		ft2_lstadd_back(&new_list, new_elem);
	}
	return (new_list);
}
