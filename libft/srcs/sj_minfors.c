/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_minfors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:41:49 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:58:50 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		sj_minfors(t_print *t)
{
	int		i;
	int		y;
	char	*vide;

	i = 0;
	y = 0;
	vide = NULL;
	while (t->gestion[y] == '-')
		y++;
	i = ft_atoi(t->gestion + y) - ft_strilen(t->x_write.str);
	while (i > 0)
	{
		i--;
		vide = sj_free_add(vide, ' ');
	}
	if (sj_minfors_b(t, vide))
		return (1);
	return (0);
}

int		sj_minfors_b(t_print *t, char *vide)
{
	char	*str;

	if (t->gestion[0] == '-')
	{
		str = sj_free_join(t->x_write.str, vide, 2);
		free(t->x_write.str);
		t->x_write.str = NULL;
		t->x_write.finish = sj_free_join(t->x_write.finish, str, 1);
		return (1);
	}
	else if (vide)
	{
		str = sj_free_join(vide, t->x_write.str, 0);
		t->x_write.finish = sj_free_join(t->x_write.finish, str, 0);
		free(str);
		return (1);
	}
	return (0);
}

int		sj_minprecs(t_print *t)
{
	int		prec;
	int		larg;
	int		i;
	int		min;

	prec = 0;
	larg = 0;
	i = 0;
	min = 0;
	if (ft_strchr(ft_strchr(t->gestion, '.'), '-') && t->flags[0] != 's')
		return (0);
	while (t->gestion[larg] == '-')
		larg++;
	prec = ft_atoi(t->gestion + larg);
	while (ft_strchr(t->gestion, '.')
		&& ft_strchr(t->gestion, '.')[min + 1] == '-')
		min++;
	larg = ft_atoi(ft_strchr(t->gestion, '.') + min + 1);
	while (larg-- > 0 && t->x_write.str && t->x_write.str[i])
		i = sj_minprecs_loop(t, i, min);
	prec -= i;
	while (prec-- > 0)
		t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
	return (1);
}

void	sj_minus_for_c(t_print *t, t_norm *nor)
{
	char	*temp;

	if ((ft_strchr(t->gestion, '.') + 1)
		&& !nor->prec && !nor->nb && t->point)
		nor->str = sj_free_join(nor->str, " ", 0);
	else
	{
		temp = ft_ltoa(nor->nb);
		nor->str = sj_free_join(nor->str, temp, 0);
		free(temp);
	}
}

int		sj_minprecs_loop(t_print *t, int i, int min)
{
	if (ft_strchr(t->gestion, '.')
		&& ft_strchr(t->gestion, '.')[min] == '-')
	{
		i += ft_strilen(t->x_write.str);
		t->x_write.finish =
			sj_free_join(t->x_write.finish, t->x_write.str, 1);
		t->x_write.str = NULL;
	}
	else
		t->x_write.finish =
			sj_free_add(t->x_write.finish, t->x_write.str[i++]);
	return (i);
}
