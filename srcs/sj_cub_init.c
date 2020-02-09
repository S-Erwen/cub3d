/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_cub_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:56:07 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 05:02:24 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sj_cub_init(t_cub *cub)
{
	cub->dbl_pos_x = 0;
	cub->dbl_pos_y = 0;
	cub->pos = 0;
	cub->path_no = NULL;
	cub->path_so = NULL;
	cub->path_we = NULL;
	cub->path_ea = NULL;
	cub->path_sprit = NULL;
	cub->line_map = NULL;
	cub->tab_map = NULL;
	cub->mlx = NULL;
	cub->windows = NULL;
	cub->img_ptr = NULL;
	cub->res_x = 0;
	cub->res_y = 0;
	cub->init_pos_x = 0;
	cub->init_pos_y = 0;
	cub->f_color_r = 0;
	cub->f_color_g = 0;
	cub->f_color_b = 0;
	cub->c_color_r = 0;
	cub->c_color_g = 0;
	cub->c_color_b = 0;
	cub->help = 0;
	sj_cub_init_ii(cub);
}

void	sj_cub_init_ii(t_cub *cub)
{
	cub->pc = 0;
	cub->x = 0;
	cub->y = 0;
	cub->bpp = 0;
	cub->size_line = 0;
	cub->endian = 0;
	cub->img_data = 0;
	cub->key->up = 0;
	cub->key->down = 0;
	cub->key->left = 0;
	cub->key->right = 0;
	cub->key->mv_right = 0;
	cub->key->mv_left = 0;
	cub->cast->dir_x = 0;
	cub->cast->dir_y = 0;
	cub->cast->cam_plane_x = 0;
	cub->cast->cam_plane_y = 0;
	cub->cast->cameraX = 0;
	cub->cast->raydir_x = 0;
	cub->cast->raydir_y = 0;
	cub->cast->pos_x = 0;
	cub->cast->pos_y = 0;
	cub->cast->time = 0;
	cub->cast->oldtime = 0;
	sj_cub_init_iii(cub);
}

void	sj_cub_init_iii(t_cub *cub)
{
	cub->cast->sidedistx = 0;
	cub->cast->sidedisty = 0;
	cub->cast->deltadistx = 0;
	cub->cast->deltadisty = 0;
	cub->cast->perpwalldist = 0;
	cub->cast->size_max_x = 0;
	cub->cast->x = 0;
	cub->cast->frametime = 0;
	cub->cast->move_speed = 0;
	cub->cast->rotation_speed = 0;
	cub->cast->old_dir_x = 0;
	cub->cast->oldcam_plane_x = 0;
	cub->cast->str = NULL;
	cub->cast->mapx = 0;
	cub->cast->mapy = 0;
	cub->cast->stepX = 0;
	cub->cast->stepY = 0;
	cub->cast->hit = 0;
	cub->cast->side = 0;
	cub->cast->lineheight = 0;
	cub->cast->drawstart = 0;
	cub->cast->drawend = 0;
	cub->cast->color = 0;
}
