/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_zero.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/23 14:56:54 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:38:18 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_zero_to_finish(t_print *t)
{
	int		i;

	i = 0;
	t->x_parce.atoi_of_gestion = ft_atoi(t->gestion);
	if (t->x_parce.atoi_of_gestion < 0)
		t->x_parce.atoi_of_gestion *= -1;
	if (t->x_write.str[i] == '-')
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, t->x_write.str[i]);
		i++;
	}
	while (t->x_write.str[i] == '-')
		i++;
	while (0 < (t->x_parce.atoi_of_gestion - ft_strilen(t->x_write.str))
		&& t->x_parce.atoi_of_gestion > 0)
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, '0');
		t->x_parce.atoi_of_gestion--;
	}
	while (t->x_write.str[i])
		t->x_write.finish = sj_free_add(t->x_write.finish, t->x_write.str[i++]);
	t->minus = 0;
	t->zero = 0;
	t->point = 0;
	return ;
}
