/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_init_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:15:56 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/05 18:03:56 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
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
	C->SP->txt_sp = (int *)mlx_get_data_addr(C->SP->adrs_sp, &bpp,
		&C->SP->size, &endian);
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
	C->xpm_adrs[0] = mlx_xpm_file_to_image(C->mlx, C->path_ea, &C->xpm_x[0],
		&C->xpm_y[0]);
	C->xpm_adrs[1] = mlx_xpm_file_to_image(C->mlx, C->path_we, &C->xpm_x[1],
		&C->xpm_y[1]);
	C->xpm_adrs[2] = mlx_xpm_file_to_image(C->mlx, C->path_no, &C->xpm_x[2],
		&C->xpm_y[2]);
	C->xpm_adrs[3] = mlx_xpm_file_to_image(C->mlx, C->path_so, &C->xpm_x[3],
		&C->xpm_y[3]);
	C->SP->adrs_sp = mlx_xpm_file_to_image(C->mlx, C->path_sprit, &C->SP->x_sp,
		&C->SP->y_sp);
	if (!C->xpm_adrs[0] || !C->xpm_adrs[1] || !C->xpm_adrs[2]
		|| !C->xpm_adrs[3] || !C->SP->adrs_sp)
	{
		ft_printf(RED);
		ft_printf("Error\n");
		sj_stderr_parsing(-15);
	}
	sj_get_adrs(cub);
}

void	sj_init_cast(t_cub *cub)
{
	sj_dir_init(cub);
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
	float	rot;

	rot = 0;
	C->CS->dir_x = -1;
	C->CS->cam_plane_y = -0.66;
	if (C->pos == 'N')
		rot = 4.71;
	if (C->pos == 'S')
		rot = 1.58;
	if (C->pos == 'E')
		rot = 3.14;
	C->CS->old_dir_x = C->CS->dir_x;
	C->CS->dir_x = C->CS->dir_x * cos(-rot) - C->CS->dir_y * sin(-rot);
	C->CS->dir_y = C->CS->old_dir_x * sin(-rot) + C->CS->dir_y * cos(-rot);
	C->CS->oldcam_plane_x = C->CS->cam_plane_x;
	C->CS->cam_plane_x = C->CS->cam_plane_x * cos(-rot) - C->CS->cam_plane_y
		* sin(-rot);
	C->CS->cam_plane_y = C->CS->oldcam_plane_x * sin(-rot) + C->CS->cam_plane_y
		* cos(-rot);
}