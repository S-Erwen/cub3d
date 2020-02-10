/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_init_all_x_y.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 11:57:08 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:52 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_init_start_dda(t_cub *cub)
{
	C->C->cameraX = 2 * C->C->x / (double)C->C->size_max_x - 1;
	C->C->raydir_x = C->C->dir_x + C->C->cam_plane_x
		* C->C->cameraX;
	C->C->raydir_y = C->C->dir_y + C->C->cam_plane_y
		* C->C->cameraX;
	C->C->mapx = (int)C->C->pos_x;
	C->C->mapy = (int)C->C->pos_y;
	C->C->deltadistx = sj_abs(1 / C->C->raydir_x);
	C->C->deltadisty = sj_abs(1 / C->C->raydir_y);
	C->C->hit = 0;
}

void	sj_raydir_step(t_cub *cub)
{
	if (C->C->raydir_x < 0)
	{
		C->C->stepX = -1;
		C->C->sidedistx = (C->C->pos_x - C->C->mapx)
			* C->C->deltadistx;
	}
	else
	{
		C->C->stepX = 1;
		C->C->sidedistx = (C->C->mapx + 1.0 - C->C->pos_x)
			* C->C->deltadistx;
	}
	if (C->C->raydir_y < 0)
	{
		C->C->stepY = -1;
		C->C->sidedisty = (C->C->pos_y - C->C->mapy)
			* C->C->deltadisty;
	}
	else
	{
		C->C->stepY = 1;
		C->C->sidedisty = (C->C->mapy + 1.0 - C->C->pos_y)
			* C->C->deltadisty;
	}
}

void	sj_hit_dist(t_cub *cub)
{
	while (C->C->hit == 0)
	{
		if (C->C->sidedistx < C->C->sidedisty)
		{
			C->C->sidedistx += C->C->deltadistx;
			C->C->mapx += C->C->stepX;
			C->C->side = 0;
		}
		else
		{
			C->C->sidedisty += C->C->deltadisty;
			C->C->mapy += C->C->stepY;
			C->C->side = 2;
		}
		if (C->tab_map[C->C->mapy][C->C->mapx] == '1')
			C->C->hit = 1;
	}
	sj_hit(cub);
}

void	sj_time(t_cub *cub)
{
	C->C->move_speed = 0.06f;
	C->C->rotation_speed = 0.06f;
}
