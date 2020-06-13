/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_part_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 09:57:29 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:22 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_flag_s_b(t_print *t)
{
	int		le_s;

	le_s = ft_strlen(t->x_write.str);
	while (0 < (t->x_parce.atoi_of_gestion - ft_atoi(t->x_parce.gest + 1))
		&& t->x_parce.atoi_of_gestion > 0
		&& (ft_atoi(t->gestion) > ft_atoi(ft_strchr(t->gestion, '.') + 1)))
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
		t->x_parce.atoi_of_gestion--;
	}
	while (le_s < t->x_parce.atoi_of_gestion)
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
		t->x_parce.atoi_of_gestion--;
	}
}

void	sj_point_or_finish_cut_one(t_print *t)
{
	while (t->x_parce.atoi_of_gestion && t->x_write.str[t->x_parce.i])
	{
		t->x_parce.atoi_of_gestion--;
		t->x_write.finish = sj_free_add(t->x_write.finish,
			t->x_write.str[t->x_parce.i++]);
	}
}

int		sj_point_or_finish_cut_tho(t_print *t)
{
	if (!(ft_neg_atoi(t->gestion) + ft_atoi(t->x_parce.gest + 1)))
		return (1);
	if (ft_strlen(t->gestion) != 1)
		t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
	free(t->x_parce.gest);
	return (1);
}

int		sj_point_or_finish_cut_elif(t_print *t)
{
	if (t->flags[0] == 's' && t->point)
	{
		sj_point_or_finish_cut_one(t);
		return (2);
	}
	else if (!ft_atoi(t->x_write.str)
		&& (t->flags[0] == 'd' || t->flags[0] == 'u' || t->flags[0] == 'i')
		&& t->x_parce.gest && ft_atoi(t->x_parce.gest + 1)
		&& !t->zero && sj_not_found_number(t->x_parce.gest + 1))
	{
		sj_point_or_finish_cut_tho(t);
		return (1);
	}
	else if ((t->flags[0] == 'd' || t->flags[0] == 'u' || t->flags[0] == 'i')
		&& !ft_atoi(t->x_write.str) && t->x_parce.gest
		&& !t->zero && sj_not_found_number(t->x_parce.gest + 1))
	{
		if (ft_atoi(t->gestion))
			t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
		return (1);
	}
	return (0);
}

int		sj_point_or_finish_nb(t_print *t)
{
	char	*temp;
	int		nb;

	temp = ft_strchr(t->gestion, '.');
	if (temp && temp + 1)
		nb = ft_atoi(temp + 1);
	else
		nb = -1;
	return (nb);
}
