/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_init_cast.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 12:15:56 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 04:54:27 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_init_cast(t_cub *cub)
{
	sj_dir_init(cub);
	cub->cast->dir_y = 0;
	cub->cast->cam_plane_x = 0;
	cub->cast->time = 0;
	cub->cast->oldtime = 0;
	cub->cast->x = 0;
	cub->bpp = 32;
	cub->size_line = cub->res_x * 4;
	cub->endian = 1;
	cub->cast->pos_x = cub->dbl_pos_x;
	cub->cast->pos_y = cub->dbl_pos_y;
	cub->cast->size_max_x = cub->res_x;
	cub->img_ptr = mlx_new_image(cub->mlx, cub->res_x, cub->res_y);
	cub->img_data = (int *)mlx_get_data_addr(cub->img_ptr,
		&cub->bpp, &cub->size_line, &cub->endian);
}

void	sj_dir_init(t_cub *cub)
{
	if (cub->pos == 'N')
	{
		cub->cast->dir_x = -1;
		cub->cast->cam_plane_y = 0.66f;
	}
	if (cub->pos == 'S')
	{
		cub->cast->dir_x = 1;
		cub->cast->cam_plane_y = -0.66f;
	}
	if (cub->pos == 'E')
	{
		cub->cast->dir_x = 1;
		cub->cast->cam_plane_y = 0.66f;
	}
	if (cub->pos == 'W')
	{
		cub->cast->dir_x = -1;
		cub->cast->cam_plane_y = -0.66f;
	}
}
