/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_windows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 04:44:53 by esidelar          #+#    #+#             */
/*   Updated: 2020/02/26 06:00:17 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

int		sj_close(void)
{
	exit(EXIT_SUCCESS);
}

int		sj_dda(t_cub *cub)
{
	C->CS->x = 0;
	C->height = C->res_y / 1.35;
	if (!(C->SP->zbuffer = malloc(sizeof(float) * (C->CS->size_max_x - 1))))
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
	sj_sprite(cub);
	sj_time(cub);
	sj_move(cub);
	mlx_clear_window(C->mlx, C->windows);
	mlx_put_image_to_window(C->mlx, C->windows, C->img_ptr, 0, 0);
	free(C->SP->zbuffer);
	return (1);
}

int		sj_move(t_cub *cub)
{
	if (C->key->down)
		sj_key_down(cub);
	if (C->key->mv_right)
		sj_key_mv_right(cub);
	if (C->key->mv_left)
		sj_key_mv_left(cub);
	if (C->key->left)
		sj_key_left(cub);
	if (C->key->right)
		sj_key_right(cub);
	if (C->key->up)
		sj_key_up(cub);
	return (1);
}

void	sj_creat_new_windows(t_cub *cub)
{
	C->mlx = mlx_init();
	sj_init_cast(cub);
	C->windows = mlx_new_window(C->mlx, C->res_x, C->res_y, "Cub3D");
	mlx_do_key_autorepeaton(C->mlx);
	mlx_loop_hook(C->mlx, sj_dda, cub);
	mlx_hook(C->windows, 2, 0, sj_key_press, cub);
	mlx_hook(C->windows, 3, 0, sj_key_release, cub);
	mlx_hook(C->windows, 17, 0, sj_close, cub);
	mlx_loop(C->mlx);
}
