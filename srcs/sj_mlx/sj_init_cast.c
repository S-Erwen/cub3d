/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_init_cast.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 12:15:56 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 07:45:06 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_get_adrs(t_cub *cub)
{
	int	bpp;
	int	size;
	int	endian;
	int	i;

	i = 0;
	C->endian = 1;
	C->SP->txt_sp = (int *)mlx_get_data_addr(C->SP->adrs_sp, &bpp, &size,
		&endian);
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

void	sj_init_image(t_cub *cub)
{
	C->xpm_adrs[0] = mlx_xpm_file_to_image(C->mlx, C->path_no, &C->xpm_x[0],
		&C->xpm_y[0]);
	C->xpm_adrs[1] = mlx_xpm_file_to_image(C->mlx, C->path_so, &C->xpm_x[1],
		&C->xpm_y[1]);
	C->xpm_adrs[2] = mlx_xpm_file_to_image(C->mlx, C->path_we, &C->xpm_x[2],
		&C->xpm_y[2]);
	C->xpm_adrs[3] = mlx_xpm_file_to_image(C->mlx, C->path_ea, &C->xpm_x[3],
		&C->xpm_y[3]);
	C->SP->adrs_sp = mlx_xpm_file_to_image(C->mlx, C->path_sprit, &C->SP->x_sp,
		&C->SP->y_sp);
	sj_get_adrs(cub);
}

void	sj_init_cast(t_cub *cub)
{
	sj_dir_init(cub);
	C->CS->dir_y = 0;
	C->CS->cam_plane_x = 0;
	C->CS->time = 0;
	C->CS->oldtime = 0;
	C->CS->x = 0;
	C->bpp = 32;
	C->size_line = C->res_x * 4;
	C->CS->pos_x = C->dbl_pos_x;
	C->CS->pos_y = C->dbl_pos_y;
	C->CS->size_max_x = C->res_x;
	sj_init_image(cub);
}

void	sj_dir_init(t_cub *cub)
{
	if (C->pos == 'N')
	{
		C->CS->dir_x = -1;
		C->CS->cam_plane_y = 0.66f;
	}
	if (C->pos == 'S')
	{
		C->CS->dir_x = 1;
		C->CS->cam_plane_y = -0.66f;
	}
	if (C->pos == 'E')
	{
		C->CS->dir_x = 1;
		C->CS->cam_plane_y = 0.66f;
	}
	if (C->pos == 'W')
	{
		C->CS->dir_x = -1;
		C->CS->cam_plane_y = -0.66f;
	}
}
