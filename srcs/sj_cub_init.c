/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_cub_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:56:07 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:56:37 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sj_cub_init(t_cub *cub)
{
	C->dbl_pos_x = 0;
	C->dbl_pos_y = 0;
	C->pos = 0;
	C->path_no = NULL;
	C->path_so = NULL;
	C->path_we = NULL;
	C->path_ea = NULL;
	C->path_sprit = NULL;
	C->line_map = NULL;
	C->tab_map = NULL;
	C->mlx = NULL;
	C->windows = NULL;
	C->img_ptr = NULL;
	C->res_x = 0;
	C->res_y = 0;
	C->init_pos_x = 0;
	C->init_pos_y = 0;
	C->f_color_r = 0;
	C->f_color_g = 0;
	C->f_color_b = 0;
	C->c_color_r = 0;
	C->c_color_g = 0;
	C->c_color_b = 0;
	C->help = 0;
	sj_cub_init_ii(cub);
}

void	sj_cub_init_ii(t_cub *cub)
{
	C->pc = 0;
	C->x = 0;
	C->y = 0;
	C->bpp = 0;
	C->size_line = 0;
	C->endian = 0;
	C->img_data = 0;
	C->key->up = 0;
	C->key->down = 0;
	C->key->left = 0;
	C->key->right = 0;
	C->key->mv_right = 0;
	C->key->mv_left = 0;
	C->C->dir_x = 0;
	C->C->dir_y = 0;
	C->C->cam_plane_x = 0;
	C->C->cam_plane_y = 0;
	C->C->cameraX = 0;
	C->C->raydir_x = 0;
	C->C->raydir_y = 0;
	C->C->pos_x = 0;
	C->C->pos_y = 0;
	C->C->time = 0;
	C->C->oldtime = 0;
	sj_cub_init_iii(cub);
}

void	sj_cub_init_iii(t_cub *cub)
{
	C->C->sidedistx = 0;
	C->C->sidedisty = 0;
	C->C->deltadistx = 0;
	C->C->deltadisty = 0;
	C->C->perpwalldist = 0;
	C->C->size_max_x = 0;
	C->C->x = 0;
	C->C->frametime = 0;
	C->C->move_speed = 0;
	C->C->rotation_speed = 0;
	C->C->old_dir_x = 0;
	C->C->oldcam_plane_x = 0;
	C->C->str = NULL;
	C->C->mapx = 0;
	C->C->mapy = 0;
	C->C->stepX = 0;
	C->C->stepY = 0;
	C->C->hit = 0;
	C->C->side = 0;
	C->C->lineheight = 0;
	C->C->drawstart = 0;
	C->C->drawend = 0;
	C->C->color = 0;
	return (sj_cub_init_iv(cub));
}

void	sj_cub_init_iv(t_cub *cub)
{
	C->texnum = 0;
	C->wallx = 0;
	C->step = 0;
	C->texpos = 0;
	C->texx = 0;
	C->texy = 0;
}