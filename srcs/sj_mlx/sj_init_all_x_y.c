/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_init_all_x_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:57:08 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:05:45 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_init_start_dda(t_cub *cub)
{
	C->CS->camera_x = 2 * C->CS->x / (double)C->CS->size_max_x - 1;
	C->CS->raydir_x = C->CS->dir_x + C->CS->cam_plane_x
		* C->CS->camera_x;
	C->CS->raydir_y = C->CS->dir_y + C->CS->cam_plane_y
		* C->CS->camera_x;
	C->CS->mapx = (int)C->CS->pos_x;
	C->CS->mapy = (int)C->CS->pos_y;
	C->CS->deltadistx = fabsf(1 / C->CS->raydir_x);
	C->CS->deltadisty = fabsf(1 / C->CS->raydir_y);
	C->CS->hit = 0;
}

void	sj_raydir_step(t_cub *cub)
{
	if (C->CS->raydir_x < 0)
	{
		C->CS->step_x = -1;
		C->CS->sidedistx = (C->CS->pos_x - C->CS->mapx)
			* C->CS->deltadistx;
	}
	else
	{
		C->CS->step_x = 1;
		C->CS->sidedistx = (C->CS->mapx + 1.0 - C->CS->pos_x)
			* C->CS->deltadistx;
	}
	if (C->CS->raydir_y < 0)
	{
		C->CS->step_y = -1;
		C->CS->sidedisty = (C->CS->pos_y - C->CS->mapy)
			* C->CS->deltadisty;
	}
	else
	{
		C->CS->step_y = 1;
		C->CS->sidedisty = (C->CS->mapy + 1.0 - C->CS->pos_y)
			* C->CS->deltadisty;
	}
}

void	sj_hit_dist(t_cub *cub)
{
	while (C->CS->hit == 0)
	{
		if (C->CS->sidedistx < C->CS->sidedisty)
		{
			C->CS->sidedistx += C->CS->deltadistx;
			C->CS->mapx += C->CS->step_x;
			C->CS->side = 0;
		}
		else
		{
			C->CS->sidedisty += C->CS->deltadisty;
			C->CS->mapy += C->CS->step_y;
			C->CS->side = 2;
		}
		if (C->tab_map[C->CS->mapy][C->CS->mapx] == '1')
			C->CS->hit = 1;
	}
	sj_hit(cub);
}

void	sj_time(t_cub *cub)
{
	double	move_clc;

	move_clc = (((float)C->res_y / 720) * ((float)C->res_x / 1280));
	if (C->res_y > 720 || C->res_x > 1280)
		move_clc = 1;
	C->CS->move_speed = 0.06f * move_clc;
	C->CS->rotation_speed = 0.06f * move_clc;
}
