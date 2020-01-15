/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 11:51:57 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 18:02:30 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*maillon;

	maillon = ft_lstlast(*alst);
	if (maillon == 0)
	{
		new->next = NULL;
		*alst = new;
	}
	else
		maillon->next = new;
}
