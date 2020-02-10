/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_view.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 05:04:15 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:08 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_key_right(t_cub *cub)
{
	C->C->old_dir_x = C->C->dir_x;
	C->C->dir_x = C->C->dir_x
		* cos(-C->C->rotation_speed) - C->C->dir_y
		* sin(-C->C->rotation_speed);
	C->C->dir_y = C->C->old_dir_x
		* sin(-C->C->rotation_speed) + C->C->dir_y
		* cos(-C->C->rotation_speed);
	C->C->oldcam_plane_x = C->C->cam_plane_x;
	C->C->cam_plane_x = C->C->cam_plane_x
		* cos(-C->C->rotation_speed) - C->C->cam_plane_y
		* sin(-C->C->rotation_speed);
	C->C->cam_plane_y = C->C->oldcam_plane_x
		* sin(-C->C->rotation_speed) + C->C->cam_plane_y
		* cos(-C->C->rotation_speed);
}

void	sj_key_left(t_cub *cub)
{
	C->C->old_dir_x = C->C->dir_x;
	C->C->dir_x = C->C->dir_x
		* cos(C->C->rotation_speed) - C->C->dir_y
		* sin(C->C->rotation_speed);
	C->C->dir_y = C->C->old_dir_x
		* sin(C->C->rotation_speed) + C->C->dir_y
		* cos(C->C->rotation_speed);
	C->C->oldcam_plane_x = C->C->cam_plane_x;
	C->C->cam_plane_x = C->C->cam_plane_x
		* cos(C->C->rotation_speed) - C->C->cam_plane_y
		* sin(C->C->rotation_speed);
	C->C->cam_plane_y = C->C->oldcam_plane_x
		* sin(C->C->rotation_speed) + C->C->cam_plane_y
		* cos(C->C->rotation_speed);
}
