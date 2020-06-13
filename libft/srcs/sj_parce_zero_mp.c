/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parce_zero_mp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:34:40 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:06 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		sj_not_found_number(char *str)
{
	int		i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] == '0')
		i++;
	if (str[i] != '0' && str[i] != '\0')
		return (0);
	else
		return (1);
}

void	sj_c_equal_zero(t_print *t)
{
	t->x_parce.gest = NULL;
	t->x_parce.atoi_of_gestion = ft_neg_atoi(t->gestion);
	if (t->flags[0] == 'c' && t->x_write.str[0] == 0)
	{
		t->x_parce.atoi_of_gestion++;
		t->cheat++;
	}
}

int		sj_x_equal_zero(t_print *t)
{
	if (t->gestion && ft_strchr(t->gestion, '.'))
	{
		t->x_parce.gest = ft_strdup(ft_strchr(t->gestion, '.'));
		t->x_parce.reset = 1;
	}
	if (!t->zero && !t->minus && t->point && !t->x_parce.atoi_of_gestion
		&& (t->flags[0] == 'x' || t->flags[0] == 'X')
		&& ft_atoi(t->x_write.str) == 0 && sj_not_found_number(t->x_write.str)
		&& !ft_atoi(t->x_parce.gest + 1))
	{
		free(t->x_write.str);
		t->x_write.str = NULL;
		return (1);
	}
	return (0);
}

void	sj_minus_and_point(t_print *t)
{
	char	*temp;

	if ((t->x_write.str[0] == '-' &&
		ft_strchr(t->gestion, '.') && ft_strchr(t->gestion, '-')))
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, '-');
		temp = ft_strdup(t->x_write.str + 1);
		free(t->x_write.str);
		t->x_write.str = ft_strdup(temp);
		free(temp);
	}
}

int		sj_forp(t_print *t)
{
	char	*temp;

	temp = ft_strdup(t->x_write.str + 2);
	free(t->x_write.str);
	t->x_write.str = ft_strdup(temp);
	free(temp);
	return (1);
}
