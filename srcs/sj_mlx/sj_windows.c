/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_windows.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 04:44:53 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 06:05:39 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_key_press(int key, t_mlx *mlx)
{
	dprintf(1, "KEY = {%d}\n", key);
	if (key == L_DOWN)
	{
		mlx->key->down = 1;
		mlx->x++;
		mlx_pixel_put(mlx->mlx, mlx->windows, mlx->y, mlx->x, OXRESET);
	}
	if (key == L_RIGHT)
	{
		mlx->y++;
		mlx_pixel_put(mlx->mlx, mlx->windows, mlx->y, mlx->x, OXRESET);
	}
	if (key == L_LEFT)
	{
		mlx->y--;
		mlx_pixel_put(mlx->mlx, mlx->windows, mlx->y, mlx->x, OXRESET);
	}
	if (key == L_UP)
	{
		mlx->x--;
		mlx_pixel_put(mlx->mlx, mlx->windows, mlx->y, mlx->x, OXRESET);
	}
	if (key == ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}

void	sj_creat_new_windows(t_mlx *mlx, t_cub *cub)
{
	int		i;
	int		y;
	// t_key	key;

	i = cub->res_x / 2;
	y = cub->res_y / 2;
	mlx->x = 0;
	mlx->y = 0;
	mlx->mlx = mlx_init();
	mlx->windows = mlx_new_window(mlx->mlx, cub->res_x, cub->res_y, "Cub3D");
	while (i < cub->res_x / 2 + cub->res_x / 2 / 2)
		mlx_pixel_put(mlx->mlx, mlx->windows, i++, 540, OXRESET);
	i = cub->res_y / 2;
	while (y < cub->res_x / 2 + cub->res_x / 2 / 2)
	{
		while (i < cub->res_x / 2 + cub->res_x / 2 / 2)
			mlx_pixel_put(mlx->mlx, mlx->windows, y, i++, OXRESET);
		y++;
		i = cub->res_y / 2;;
	}
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx_hook(mlx->windows, 2, 0, sj_key_press, mlx);
	mlx_hook(mlx->windows, 3, 0, sj_key_release, mlx);
	mlx_key_hook(mlx->windows, sj_key, mlx);
	mlx_loop(mlx->mlx);
}
