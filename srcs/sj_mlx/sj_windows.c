/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 04:44:53 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:20:14 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_close(t_cub *cub)
{
	ult_i_to_vii(-99, cub);
	exit(EXIT_SUCCESS);
}

int		sj_dda(t_cub *cub)
{
	C->CS->x = 0;
	C->height = C->res_y / 1.35;
	if (!(C->SP->zbuffer = malloc(sizeof(float) * (C->CS->size_max_x))))
		return (0);
	while (C->CS->x < C->CS->size_max_x)
	{
		sj_init_start_dda(cub);
		sj_raydir_step(cub);
		sj_hit_dist(cub);
		sj_draw_start_end(cub);
		sj_draw(cub);
		C->SP->zbuffer[(int)C->CS->x] = C->CS->perpwalldist;
		C->CS->x++;
	}
	sj_tab_sprite(cub);
	sj_sprite(cub);
	sj_time(cub);
	sj_move(cub);
	if (C->help && C->bmp->reset)
		sj_write_bmp(cub);
	mlx_clear_window(C->mlx, C->windows);
	mlx_put_image_to_window(C->mlx, C->windows, C->img_ptr, 0, 0);
	free(C->SP->zbuffer);
	return (1);
}

int		sj_move(t_cub *cub)
{
	if (C->K->down)
		sj_key_down(cub);
	if (C->K->mv_right)
		sj_key_mv_right(cub);
	if (C->K->mv_left)
		sj_key_mv_left(cub);
	if (C->K->left)
		sj_key_left(cub);
	if (C->K->right)
		sj_key_right(cub);
	if (C->K->up)
		sj_key_up(cub);
	return (1);
}

void	sj_creat_new_windows(t_cub *cub)
{
	C->mlx = mlx_init();
	sj_init_cast(cub);
	if (C->help && C->bmp->reset)
		sj_init_bpm(cub);
	C->windows = mlx_new_window(C->mlx, C->res_x, C->res_y, "Cub3D");
	mlx_loop_hook(C->mlx, sj_dda, cub);
	mlx_hook(C->windows, 2, 2, sj_key_press, cub);
	mlx_hook(C->windows, 3, 2, sj_key_release, cub);
	mlx_hook(C->windows, 17, 1, sj_close, cub);
	mlx_loop(C->mlx);
}
