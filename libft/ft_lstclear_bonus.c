/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 05:34:26 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:01:11 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && del)
		while (*lst)
		{
			del((*lst)->content);
			free(*lst);
			*lst = (*lst)->next;
		}
	*lst = NULL;
}
