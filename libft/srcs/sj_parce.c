/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:39:31 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:11 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_precision_to_finish(t_print *t)
{
	if (sj_not_flag(t))
		return ;
	sj_c_equal_zero(t);
	if (sj_x_equal_zero(t))
		return ;
	sj_minus_and_point(t);
	if (t->flags[0] != 's')
	{
		if (sj_minus(t))
			return ;
	}
	else if (t->flags[0] == 's' && !ft_strchr(t->gestion, '.'))
	{
		if (sj_minfors(t))
			return ;
	}
	else if (t->flags[0] == 's' && ft_strchr(t->gestion, '.')
		&& ft_strchr(t->gestion, '-'))
	{
		if (sj_minprecs(t))
			return ;
	}
	t->x_parce.atoi_of_gestion = ft_neg_atoi(t->gestion);
	if (sj_precision_to_finish_b(t))
		return ;
}

int		sj_precision_to_finish_b(t_print *t)
{
	if (ft_strchr(t->gestion, '.'))
		sj_chr_of_point(t);
	else
		sj_else_not_chr_of_point(t);
	if (sj_point_or_finish(t))
		return (1);
	return (0);
}

void	sj_prec_and_flags(t_print *t)
{
	int		i;

	i = 0;
	sj_check_star(t, i);
	if ((t->zero || t->minus) && t->point)
	{
		if (t->pf[i] == '0')
		{
			i++;
			t->zero = 0;
			sj_precision_to_finish(t);
			return ;
		}
		else
			sj_precision_to_finish(t);
		return ;
	}
	else if (t->zero && !t->point && !t->minus)
		sj_zero_to_finish(t);
	else
		sj_precision_to_finish(t);
	free(t->pf);
	t->pf = NULL;
}

int		sj_check_star(t_print *t, int i)
{
	int		reset;

	reset = 0;
	while (t->pf[i])
	{
		if (t->pf[i] == '*')
		{
			if (t->star)
				t->gestion = sj_free_join(t->gestion, ft_itoa(t->star), 0);
			else
				t->gestion = sj_free_join(t->gestion, ft_itoa(t->star_two), 0);
			reset++;
			i++;
		}
		if (t->pf[i] && t->pf[i] != '*')
			t->gestion = sj_free_add(t->gestion, t->pf[i++]);
	}
	reset = sj_check_star_pt2(t, i, reset);
	return (reset);
}

int		sj_check_star_pt2(t_print *t, int i, int reset)
{
	if (t->pf[i] == '*')
	{
		if (t->star)
			t->gestion = sj_free_join(t->gestion, ft_itoa(t->star), 0);
		else
			t->gestion = sj_free_join(t->gestion, ft_itoa(t->star_two), 0);
		reset++;
	}
	return (reset);
}
