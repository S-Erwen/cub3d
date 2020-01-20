/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_part_three.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/29 10:36:45 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:38:17 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_point_or_finish_c_and_zero(t_print *t)
{
	if (t->x_write.str[0] == '0' && t->flags[0] == 'c')
		t->cheat++;
	t->x_write.finish =
		sj_free_join(t->x_write.finish, t->x_write.str, 0);
}
