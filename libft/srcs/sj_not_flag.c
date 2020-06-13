/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_not_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:59:58 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:58:57 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_not_flag_if(t_print *t, char *vide)
{
	if (t->pf[0] != '-')
	{
		vide = sj_free_join(vide, "%", 0);
		t->x_write.finish = sj_free_join(t->x_write.finish, vide, 1);
	}
	else
	{
		vide = sj_free_join("%", vide, 2);
		t->x_write.finish = sj_free_join(t->x_write.finish, vide, 1);
	}
}

int		sj_not_flag(t_print *t)
{
	int		prec;
	int		index;
	char	*vide;

	vide = NULL;
	index = 0;
	if (t->flags[0] == '%')
	{
		while (t->pf[index] == '-')
			index++;
		prec = ft_atoi(t->pf + index);
		if (prec < 0)
			prec *= -1;
		while (prec > 1)
		{
			vide = sj_free_add(vide, ' ');
			prec--;
		}
		sj_not_flag_if(t, vide);
		return (1);
	}
	return (0);
}
