/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sanjaro <sanjaro@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 11:50:08 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 04:38:57 by sanjaro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_key_down(t_cub *cub)
{
	int		x;
	int		y;

	dprintf(2, "POSX START = [%f]\n", cub->cast.pos_x);
	dprintf(2, "POSY START = [%f]\n\n", cub->cast.pos_y);

	x = (int)(cub->cast.pos_x - cub->cast.dir_x * cub->cast.move_speed);
	y = (int)(cub->cast.pos_y - cub->cast.dir_y * cub->cast.move_speed);
	if (cub->tab_map[y][x] == '0')
	{
		cub->cast.pos_x -= cub->cast.dir_x * cub->cast.move_speed;
		cub->cast.pos_y -= cub->cast.dir_y * cub->cast.move_speed;
	}
	dprintf(2, "POSX END = [%f]\n", cub->cast.pos_x);
	dprintf(2, "POSY END = [%f]\n\n\n", cub->cast.pos_y);
}

void	sj_key_right(t_cub *cub)
{
	cub->cast.old_dir_x = cub->cast.dir_x;
	cub->cast.dir_x = cub->cast.dir_x * cos(-cub->cast.rotation_speed) - cub->cast.dir_y * sin(-cub->cast.rotation_speed);
	cub->cast.dir_y = cub->cast.old_dir_x * sin(-cub->cast.rotation_speed) + cub->cast.dir_y * cos(-cub->cast.rotation_speed);
	cub->cast.oldcam_plane_x = cub->cast.cam_plane_x;
	cub->cast.cam_plane_x = cub->cast.cam_plane_x * cos(-cub->cast.rotation_speed) - cub->cast.cam_plane_y * sin(-cub->cast.rotation_speed);
	cub->cast.cam_plane_y = cub->cast.oldcam_plane_x * sin(-cub->cast.rotation_speed) + cub->cast.cam_plane_y * cos(-cub->cast.rotation_speed);
}

void	sj_key_left(t_cub *cub)
{
	cub->cast.old_dir_x = cub->cast.dir_x;
	cub->cast.dir_x = cub->cast.dir_x * cos(cub->cast.rotation_speed) - cub->cast.dir_y * sin(cub->cast.rotation_speed);
	cub->cast.dir_y = cub->cast.old_dir_x * sin(cub->cast.rotation_speed) + cub->cast.dir_y * cos(cub->cast.rotation_speed);
	cub->cast.oldcam_plane_x = cub->cast.cam_plane_x;
	cub->cast.cam_plane_x = cub->cast.cam_plane_x * cos(cub->cast.rotation_speed) - cub->cast.cam_plane_y * sin(cub->cast.rotation_speed);
	cub->cast.cam_plane_y = cub->cast.oldcam_plane_x * sin(cub->cast.rotation_speed) + cub->cast.cam_plane_y * cos(cub->cast.rotation_speed);
}

void	sj_key_up(t_cub *cub)
{
	int		x;
	int		y;

	dprintf(2, "POSX START = [%f]\n", cub->cast.pos_x);
	dprintf(2, "POSY START = [%f]\n\n", cub->cast.pos_y);
	x = (int)(cub->cast.pos_x + cub->cast.dir_x * cub->cast.move_speed);
	y = (int)(cub->cast.pos_y + cub->cast.dir_y * cub->cast.move_speed);
	if (cub->tab_map[y][x] == '0')
	{
		cub->cast.pos_x += cub->cast.dir_x * cub->cast.move_speed;
		cub->cast.pos_y += cub->cast.dir_y * cub->cast.move_speed;
	}
	dprintf(2, "POSX END = [%f]\n", cub->cast.pos_x);
	dprintf(2, "POSY END = [%f]\n\n\n", cub->cast.pos_y);
}
