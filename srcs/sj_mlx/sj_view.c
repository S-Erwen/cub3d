/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_view.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 05:04:15 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 05:05:00 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_key_right(t_cub *cub)
{
	cub->cast->old_dir_x = cub->cast->dir_x;
	cub->cast->dir_x = cub->cast->dir_x
		* cos(-cub->cast->rotation_speed) - cub->cast->dir_y
		* sin(-cub->cast->rotation_speed);
	cub->cast->dir_y = cub->cast->old_dir_x
		* sin(-cub->cast->rotation_speed) + cub->cast->dir_y
		* cos(-cub->cast->rotation_speed);
	cub->cast->oldcam_plane_x = cub->cast->cam_plane_x;
	cub->cast->cam_plane_x = cub->cast->cam_plane_x
		* cos(-cub->cast->rotation_speed) - cub->cast->cam_plane_y
		* sin(-cub->cast->rotation_speed);
	cub->cast->cam_plane_y = cub->cast->oldcam_plane_x
		* sin(-cub->cast->rotation_speed) + cub->cast->cam_plane_y
		* cos(-cub->cast->rotation_speed);
}

void	sj_key_left(t_cub *cub)
{
	cub->cast->old_dir_x = cub->cast->dir_x;
	cub->cast->dir_x = cub->cast->dir_x
		* cos(cub->cast->rotation_speed) - cub->cast->dir_y
		* sin(cub->cast->rotation_speed);
	cub->cast->dir_y = cub->cast->old_dir_x
		* sin(cub->cast->rotation_speed) + cub->cast->dir_y
		* cos(cub->cast->rotation_speed);
	cub->cast->oldcam_plane_x = cub->cast->cam_plane_x;
	cub->cast->cam_plane_x = cub->cast->cam_plane_x
		* cos(cub->cast->rotation_speed) - cub->cast->cam_plane_y
		* sin(cub->cast->rotation_speed);
	cub->cast->cam_plane_y = cub->cast->oldcam_plane_x
		* sin(cub->cast->rotation_speed) + cub->cast->cam_plane_y
		* cos(cub->cast->rotation_speed);
}
