/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_init_cast.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 12:15:56 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:25:54 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_init_cast(t_cub *cub)
{
	int	bpp;
	int	size;
	int	endian;
	int	i;

	i = 0;
	sj_dir_init(cub);
	C->C->dir_y = 0;
	C->C->cam_plane_x = 0;
	C->C->time = 0;
	C->C->oldtime = 0;
	C->C->x = 0;
	C->bpp = 32;
	C->size_line = C->res_x * 4;
	C->endian = 1;
	C->C->pos_x = C->dbl_pos_x;
	C->C->pos_y = C->dbl_pos_y;
	C->C->size_max_x = C->res_x;
	C->xpm_adrs[0] = mlx_xpm_file_to_image(C->mlx, C->path_no, &C->xpm_x[0],
		&C->xpm_y[0]);
	C->xpm_adrs[1] = mlx_xpm_file_to_image(C->mlx, C->path_so, &C->xpm_x[1],
		&C->xpm_y[1]);
	C->xpm_adrs[2] = mlx_xpm_file_to_image(C->mlx, C->path_we, &C->xpm_x[2],
		&C->xpm_y[2]);
	C->xpm_adrs[3] = mlx_xpm_file_to_image(C->mlx, C->path_ea, &C->xpm_x[3],
		&C->xpm_y[3]);
	while (i < 4)
	{
		C->xpm_txt[i] = (int *)mlx_get_data_addr(C->xpm_adrs[i],
			&bpp, &size, &endian);
		i++;
	}
	C->img_ptr = mlx_new_image(C->mlx, C->res_x, C->res_y);
	C->img_data = (int *)mlx_get_data_addr(C->img_ptr,
		&C->bpp, &C->size_line, &C->endian);
}

void	sj_dir_init(t_cub *cub)
{
	if (C->pos == 'N')
	{
		C->C->dir_x = -1;
		C->C->cam_plane_y = 0.66f;
	}
	if (C->pos == 'S')
	{
		C->C->dir_x = 1;
		C->C->cam_plane_y = -0.66f;
	}
	if (C->pos == 'E')
	{
		C->C->dir_x = 1;
		C->C->cam_plane_y = 0.66f;
	}
	if (C->pos == 'W')
	{
		C->C->dir_x = -1;
		C->C->cam_plane_y = -0.66f;
	}
}
