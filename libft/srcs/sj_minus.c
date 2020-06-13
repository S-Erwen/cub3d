/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 07:53:17 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:58:54 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int				sj_minus(t_print *t)
{
	t_norm				nor;
	long long int		i;

	i = sj_minus_reset(&nor);
	if (t->flags[0] == 'p' && t->minus)
		nor.ptr = sj_forp(t);
	if (t->point && t->minus)
		nor.prec = ft_atoi(ft_strchr(t->gestion, '.') + 1);
	if (t->minus)
	{
		while (t->gestion[i] == '-' || t->gestion[i] == '0')
			i++;
		nor.larg = ft_utoi(t->gestion + i);
		i = 0;
		if (t->flags[0] == 'u')
			nor.nb = ft_utoi(t->x_write.str);
		else
			nor.nb = ft_atoi(t->x_write.str);
		sj_minus_a(t, &nor);
		sj_minus_b(t, &nor);
		sj_minus_c(t, &nor);
		free(nor.str);
		return (1);
	}
	return (0);
}

long long int	sj_minus_reset(t_norm *nor)
{
	nor->prec = 0;
	nor->ptr = 0;
	nor->temp3 = 0;
	nor->verif = '0';
	nor->str = NULL;
	return (0);
}

void			sj_minus_a(t_print *t, t_norm *nor)
{
	if (nor->nb < 0)
		nor->nb *= -1;
	nor->temp = nor->prec;
	if (t->x_write.str[0] == '-')
		nor->str = sj_free_add(nor->str, '-');
	nor->temp -= ft_strilen(t->x_write.str);
	if (nor->ptr)
		nor->str = sj_free_join(nor->str, "0x", 0);
	while (nor->temp > 0)
	{
		nor->temp--;
		nor->str = sj_free_add(nor->str, '0');
	}
	nor->chrtemp = ft_strchr(t->gestion, '.');
	if (nor->chrtemp && nor->chrtemp + 1)
		nor->temp3 = ft_atoi(nor->chrtemp + 1);
	else
		nor->verif = 0;
}

void			sj_minus_b(t_print *t, t_norm *nor)
{
	if (t->flags[0] == 'p' || t->flags[0] == 'x'
		|| t->flags[0] == 'X')
	{
		if (!nor->temp3
		&& !ft_strncmp(t->x_write.str, "0", ft_strlen(t->x_write.str))
		&& !nor->verif && !nor->chrtemp)
			nor->str = sj_free_join(nor->str, "0", 0);
		else if (!nor->temp3
		&& nor->verif
		&& !ft_strncmp(t->x_write.str, "0", ft_strlen(t->x_write.str)
		&& !t->precision))
			nor->str = sj_free_join(nor->str, " ", 0);
		else
			nor->str = sj_free_join(nor->str, t->x_write.str, 0);
	}
	else if (t->flags[0] == '%')
		nor->str = sj_free_join(nor->str, "%", 0);
	else if (t->flags[0] != 'c')
		sj_minus_for_c(t, nor);
	else
		nor->str = sj_free_join(nor->str, t->x_write.str, 0);
	nor->temp = nor->larg;
}

void			sj_minus_c(t_print *t, t_norm *nor)
{
	if (nor->str)
		nor->temp2 = ft_strlen(nor->str);
	else
		nor->temp2 = 0;
	if (t->flags[0] == 'c' && t->x_write.str[0] == 0)
	{
		sj_reset_chr(t);
		nor->temp--;
		t->cheat--;
	}
	if (t->gestion && t->gestion[0] == '-' && t->x_write.finish
		&& t->point && (nor->larg < nor->prec
		|| t->x_write.finish[ft_strlen(t->x_write.finish) - 1] == '-')
		&& t->star >= 0 && t->star_two >= 0
		&& (t->flags[0] == 'd' || t->flags[0] == 'u' || t->flags[0] == 'i'))
		nor->temp--;
	while (nor->temp > nor->temp2)
	{
		nor->temp--;
		if (ft_strchr(t->gestion, '-'))
			nor->str = sj_free_join(nor->str, " ", 0);
		else
			nor->str = sj_free_join(" ", nor->str, 2);
	}
	t->x_write.finish = sj_free_join(t->x_write.finish, nor->str, 0);
}
