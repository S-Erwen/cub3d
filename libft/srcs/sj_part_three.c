/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_part_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:36:45 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:18 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_point_or_finish_c_and_zero(t_print *t)
{
	if (t->x_write.str[0] == '0' && t->flags[0] == 'c')
		t->cheat++;
	t->x_write.finish =
		sj_free_join(t->x_write.finish, t->x_write.str, 0);
}
