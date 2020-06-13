/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:47:45 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:01:23 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*dock;

	if (!f || !del)
		return (NULL);
	dock = NULL;
	while (lst)
	{
		if (!(elem = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&dock, del);
			return (NULL);
		}
		if (elem)
		{
			if (!dock)
				dock = elem;
			else
				ft_lstlast(dock)->next = elem;
		}
		lst = lst->next;
	}
	return (dock);
}
