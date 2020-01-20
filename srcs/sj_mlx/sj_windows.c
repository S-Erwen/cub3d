/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_windows.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 04:44:53 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 06:05:30 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_key()
{
	return (0);
}

void	sj_creat_new_windows(t_mlx *mlx, t_cub *cub)
{
	int		i;

	i = 480;
	mlx->mlx = mlx_init();
	mlx->windows = mlx_new_window(mlx->mlx, cub->res_x, cub->res_y, "Cub3D");
	while (i < 1440)
		mlx_pixel_put(mlx->mlx, mlx->windows, i++, 540, OXRESET);
	i = 540;
	while (i < 1440)
		mlx_pixel_put(mlx->mlx, mlx->windows, 960, i++, OXRESET);
	mlx_key_hook(mlx->windows, sj_key, (void *)0);
	mlx_loop(mlx->mlx);
}
