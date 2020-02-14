/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_view.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 05:04:15 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 04:56:56 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_key_right(t_cub *cub)
{
	C->CS->old_dir_x = C->CS->dir_x;
	C->CS->dir_x = C->CS->dir_x
		* cos(-C->CS->rotation_speed) - C->CS->dir_y
		* sin(-C->CS->rotation_speed);
	C->CS->dir_y = C->CS->old_dir_x
		* sin(-C->CS->rotation_speed) + C->CS->dir_y
		* cos(-C->CS->rotation_speed);
	C->CS->oldcam_plane_x = C->CS->cam_plane_x;
	C->CS->cam_plane_x = C->CS->cam_plane_x
		* cos(-C->CS->rotation_speed) - C->CS->cam_plane_y
		* sin(-C->CS->rotation_speed);
	C->CS->cam_plane_y = C->CS->oldcam_plane_x
		* sin(-C->CS->rotation_speed) + C->CS->cam_plane_y
		* cos(-C->CS->rotation_speed);
}

void	sj_key_left(t_cub *cub)
{
	C->CS->old_dir_x = C->CS->dir_x;
	C->CS->dir_x = C->CS->dir_x
		* cos(C->CS->rotation_speed) - C->CS->dir_y
		* sin(C->CS->rotation_speed);
	C->CS->dir_y = C->CS->old_dir_x
		* sin(C->CS->rotation_speed) + C->CS->dir_y
		* cos(C->CS->rotation_speed);
	C->CS->oldcam_plane_x = C->CS->cam_plane_x;
	C->CS->cam_plane_x = C->CS->cam_plane_x
		* cos(C->CS->rotation_speed) - C->CS->cam_plane_y
		* sin(C->CS->rotation_speed);
	C->CS->cam_plane_y = C->CS->oldcam_plane_x
		* sin(C->CS->rotation_speed) + C->CS->cam_plane_y
		* cos(C->CS->rotation_speed);
}
