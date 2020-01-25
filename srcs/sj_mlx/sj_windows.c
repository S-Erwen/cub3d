/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_windows.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 04:44:53 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 04:47:39 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_key_press(int key, t_mlx *mlx)
{
	dprintf(1, GREEN);
	dprintf(1, "KEY_PRESS = {%d}\n", key);
	dprintf(1, RESET);
	if (key == L_DOWN)
		mlx->key.down = 1;
	if (key == L_RIGHT)
		mlx->key.right = 1;
	if (key == L_LEFT)
		mlx->key.left = 1;
	if (key == L_UP)
		mlx->key.up = 1;
	if (key == ESCAPE)
		exit(EXIT_SUCCESS);
	if (mlx->key.down)
		mlx->y++;
	if (mlx->key.right)
		mlx->x++;
	if (mlx->key.left)
		mlx->x--;
	if (mlx->key.up)
		mlx->y--;
	mlx_pixel_put(mlx->mlx, mlx->windows, mlx->x, mlx->y, OXRESET);
	return (0);
}

int		sj_key_release(int key, t_mlx *mlx)
{
	dprintf(1, RED);
	dprintf(1, "KEY_RELEA = {%d}\n", key);
	dprintf(1, RESET);
	if (key == L_DOWN)
		mlx->key.down = 0;
	if (key == L_RIGHT)
		mlx->key.right = 0;
	if (key == L_LEFT)
		mlx->key.left = 0;
	if (key == L_UP)
		mlx->key.up = 0;
	return (0);
}

int		sj_close()
{
	exit(EXIT_SUCCESS);
}

void	sj_creat_new_windows(t_mlx *mlx, t_cub *cub)
{
	mlx->key.right = 0;
	mlx->key.left = 0;
	mlx->key.down = 0;
	mlx->key.up = 0;
	mlx->x = cub->res_x / 2;
	mlx->y = cub->res_y / 2;
	mlx->mlx = mlx_init();
	mlx->windows = mlx_new_window(mlx->mlx, cub->res_x, cub->res_y, "Cub3D");
	mlx_do_key_autorepeaton(mlx->mlx);

	
	/* TEST */

	double	dif_x;
	double	dif_y;
	double	distance;
	int		temp;
	int		tempo;

	temp = cub->init_pos_y;
	while (cub->tab_map[cub->init_pos_x][cub->init_pos_y] != '1' && cub->init_pos_y)
		cub->init_pos_y--;
	tempo = cub->init_pos_y;
	cub->init_pos_y = temp;
	dif_y = cub->init_pos_y - tempo;

	/* ------------------ */
	temp = cub->init_pos_x;
	while (cub->tab_map[cub->init_pos_x][cub->init_pos_y] != '1' && cub->init_pos_x)
		cub->init_pos_x--;
	tempo = cub->init_pos_x;
	cub->init_pos_x = temp;
	dif_x = cub->init_pos_x - tempo;


	distance = sqrt(pow(dif_x, 2) + pow(dif_y, 2));


	/* MOVE */
	mlx_hook(mlx->windows, 2, 0, sj_key_press, mlx);
	mlx_hook(mlx->windows, 17, 0, sj_close, mlx);
	mlx_hook(mlx->windows, 3, 0, sj_key_release, mlx);
	mlx_loop(mlx->mlx);
}

	// while (i < cub->res_x / 2 + cub->res_x / 2 / 2)
	// 	mlx_pixel_put(mlx->mlx, mlx->windows, i++, 540, OXRESET);
	// i = cub->res_y / 2;
	// while (y < cub->res_x / 2 + cub->res_x / 2 / 2)
	// {
	// 	while (i < cub->res_x / 2 + cub->res_x / 2 / 2)
	// 		mlx_pixel_put(mlx->mlx, mlx->windows, y, i++, OXRESET);
	// 	y++;
	// 	i = cub->res_y / 2;;
	// }