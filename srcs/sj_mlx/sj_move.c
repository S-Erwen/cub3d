/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 11:50:08 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/30 11:54:17 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_key_down(t_cub *cub)
{
	cub->cast.one = (int)(cub->cast.pos_x - cub->cast.dir_x * cub->cast.move_speed);
	cub->cast.tho = (int)cub->cast.pos_y;
	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
		cub->cast.pos_x -= cub->cast.dir_x * cub->cast.move_speed;
	cub->cast.one = (int)cub->cast.pos_x;
	cub->cast.tho = (int)(cub->cast.pos_y - cub->cast.dir_y * cub->cast.move_speed);
	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
		cub->cast.pos_y -= cub->cast.dir_y * cub->cast.move_speed;
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
	cub->cast.one = (int)(cub->cast.pos_x + cub->cast.dir_x * cub->cast.move_speed);
	cub->cast.tho = (int)cub->cast.pos_y;
	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
		cub->cast.pos_x += cub->cast.dir_x * cub->cast.move_speed;
	cub->cast.one = (int)cub->cast.pos_x;
	cub->cast.tho = (int)cub->cast.pos_y + cub->cast.dir_y * cub->cast.move_speed;
	if (cub->tab_map[cub->cast.one][cub->cast.tho] == '0')
		cub->cast.pos_y += cub->cast.dir_y * cub->cast.move_speed;
}
