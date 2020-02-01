/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_init_all_x_y.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 11:57:08 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 01:40:00 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_init_start_dda(t_cub *cub)
{
	cub->cast.cameraX = 2 * cub->cast.x / cub->cast.size_max_x - 1;
	cub->cast.raydir_x = cub->cast.dir_x + cub->cast.cam_plane_x * cub->cast.cameraX;
	cub->cast.raydir_y = cub->cast.dir_y + cub->cast.cam_plane_y * cub->cast.cameraX;
	cub->cast.mapx = cub->cast.pos_x;
	cub->cast.mapy = cub->cast.pos_y;
	cub->cast.deltadistx = sj_abs(1 / cub->cast.raydir_x);
	cub->cast.deltadisty = sj_abs(1 / cub->cast.raydir_y);
	cub->cast.hit = 0;
}

void	sj_raydir_step(t_cub *cub)
{
	if (cub->cast.raydir_x < 0)
	{
		cub->cast.stepX = -1;
		cub->cast.sidedistx = (cub->cast.pos_x - cub->cast.mapx) * cub->cast.deltadistx;
	}
	else
	{
		cub->cast.stepX = 1;
		cub->cast.sidedistx = (cub->cast.mapx + 1.0 - cub->cast.pos_x) * cub->cast.deltadistx;
	}
	if (cub->cast.raydir_y < 0)
	{
		cub->cast.stepY = -1;
		cub->cast.sidedisty = (cub->cast.pos_y - cub->cast.mapy) * cub->cast.deltadisty;
	}
	else
	{
		cub->cast.stepY = 1;
		cub->cast.sidedisty = (cub->cast.mapy + 1.0 - cub->cast.pos_y) * cub->cast.deltadisty;
	}
}

void	sj_hit_dist(t_cub *cub)
{
	while (cub->cast.hit == 0)
	{
		if (cub->cast.sidedistx < cub->cast.sidedisty)
		{
			cub->cast.sidedistx += cub->cast.deltadistx;
			cub->cast.mapx += cub->cast.stepX;
			cub->cast.side = 0;
		}
		else
		{
			cub->cast.sidedisty += cub->cast.deltadisty;
			cub->cast.mapy += cub->cast.stepY;
			cub->cast.side = 1;
		}
		if (cub->tab_map[cub->cast.mapy][cub->cast.mapx] > '0')
			cub->cast.hit = 1;
	}
}

void	sj_draw_start_end(t_cub *cub)
{
	if (cub->cast.side == 0)
		cub->cast.perpwalldist = (cub->cast.mapx - cub->cast.pos_x + (1 - cub->cast.stepX) / 2) / cub->cast.raydir_x;
	else
		cub->cast.perpwalldist = (cub->cast.mapy - cub->cast.pos_y + (1 - cub->cast.stepY) / 2) / cub->cast.raydir_y;
	cub->cast.lineheight = (long int)(HEIGHT / cub->cast.perpwalldist);
	cub->cast.drawstart = -cub->cast.lineheight / 2 + HEIGHT / 2;
	if (cub->cast.drawstart < 0)
		cub->cast.drawstart = 0;
	cub->cast.drawend = cub->cast.lineheight / 2 + HEIGHT / 2;
	if (cub->cast.drawend >= cub->res_y)
		cub->cast.drawend = cub->res_y - 1;
	cub->cast.color = OXRED;
	if (cub->cast.side == 1)
		cub->cast.color = OXBLUE;
}

void	sj_time(t_cub *cub)
{
	cub->cast.move_speed = 0.06;
	cub->cast.rotation_speed = 0.06;
}
