/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_windows.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 04:44:53 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/08 09:37:29 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_close()
{
	exit(EXIT_SUCCESS);
}

float	sj_abs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int		sj_dda(t_cub *cub)
{
	int i;

	cub->cast.x = 0;
	while (cub->cast.x < cub->cast.size_max_x)
	{
		sj_init_start_dda(cub);
		sj_raydir_step(cub);
		sj_hit_dist(cub);
		/* DDA FINISH */

		sj_draw_start_end(cub);
		i = 0;
		while (i < cub->cast.drawstart)
		{
			cub->img_data[i * cub->res_x + (int)cub->cast.x] = sj_color(cub->f_color_r, cub->f_color_g, cub->f_color_b);
			i++;
		}
		while (cub->cast.drawstart < cub->cast.drawend)
			cub->img_data[cub->cast.drawstart++ * cub->res_x + (int)cub->cast.x] = cub->cast.color;
		i = cub->cast.drawend;
		while (i < cub->res_y - 1)
		{
			cub->img_data[i * cub->res_x + (int)cub->cast.x] = sj_color(cub->c_color_r, cub->c_color_g, cub->c_color_b);
			i++;
		}
		cub->cast.x++;
	}
	sj_time(cub);
	sj_move(cub);
	mlx_clear_window(cub->mlx, cub->windows);
	mlx_put_image_to_window(cub->mlx, cub->windows, cub->img_ptr, 0, 0);
	return (1);
}

int		sj_move(t_cub *cub)
{
	if (cub->key.down)
		sj_key_down(cub);
	if (cub->key.mv_right)
		sj_key_mv_right(cub);
	if (cub->key.mv_left)
		sj_key_mv_left(cub);
	if (cub->key.left)
		sj_key_left(cub);
	if (cub->key.right)
		sj_key_right(cub);
	if (cub->key.up)
		sj_key_up(cub);
	return (1);
}

int		sj_key_press(int key, t_cub *cub)
{
	dprintf(1, GREEN);
	dprintf(1, "KEY_PRESS = {%d}\n", key);
	dprintf(1, RESET);
	if (key == L_LEFT)
		cub->key.mv_left = 1;
	if (key == L_RIGHT)
		cub->key.mv_right = 1;
	if (key == L_DOWN || key == R_DOWN)
		cub->key.down = 1;
	if (key == R_RIGHT)
		cub->key.right = 1;
	if (key == R_LEFT)
		cub->key.left = 1;
	if (key == L_UP || key == R_UP)
		cub->key.up = 1;
	if (key == ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}

int		sj_key_release(int key, t_cub *cub)
{
	dprintf(1, RED);
	dprintf(1, "KEY_RELEA = {%d}\n", key);
	dprintf(1, RESET);
	if (key == L_LEFT)
		cub->key.mv_left = 0;
	if (key == L_RIGHT)
		cub->key.mv_right = 0;
	if (key == L_DOWN || key == R_DOWN)
		cub->key.down = 0;
	if (key == R_RIGHT)
		cub->key.right = 0;
	if (key == R_LEFT)
		cub->key.left = 0;
	if (key == L_UP || key == R_UP)
		cub->key.up = 0;
	return (0);
}

void	sj_creat_new_windows(t_cub *cub)
{
	cub->key.right = 0;
	cub->key.left = 0;
	cub->key.down = 0;
	cub->key.up = 0;
	cub->mlx = mlx_init();
	sj_init_cast(cub);
	cub->windows = mlx_new_window(cub->mlx, cub->res_x, cub->res_y, "Cub3D");
	mlx_do_key_autorepeaton(cub->mlx);
	mlx_loop_hook(cub->mlx, sj_dda, cub);
	mlx_hook(cub->windows, 2, 0, sj_key_press, cub);
	mlx_hook(cub->windows, 3, 0, sj_key_release, cub);
	mlx_hook(cub->windows, 17, 0, sj_close, cub);
	mlx_loop(cub->mlx);
}
