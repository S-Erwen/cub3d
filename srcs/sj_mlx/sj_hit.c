/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_hit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:50:37 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 04:51:12 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_hit(t_cub *cub)
{
	cub->cast->hit = 1;
	if (cub->cast->side == 0)
	{
		if (cub->cast->mapx < cub->cast->pos_x)
			cub->cast->side = 1;
	}
	else
	{
		if (cub->cast->mapy < cub->cast->pos_y)
			cub->cast->side = 3;
	}
}
