/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_cub_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:56:07 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 04:56:56 by esidelar    ###    #+. /#+    ###.fr     */
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
	C->K->up = 0;
	C->K->down = 0;
	C->K->left = 0;
	C->K->right = 0;
	C->K->mv_right = 0;
	C->K->mv_left = 0;
	C->CS->dir_x = 0;
	C->CS->dir_y = 0;
	C->CS->cam_plane_x = 0;
	C->CS->cam_plane_y = 0;
	C->CS->camera_x = 0;
	C->CS->raydir_x = 0;
	C->CS->raydir_y = 0;
	C->CS->pos_x = 0;
	C->CS->pos_y = 0;
	C->CS->time = 0;
	C->CS->oldtime = 0;
	sj_cub_init_iii(cub);
}

void	sj_cub_init_iii(t_cub *cub)
{
	C->CS->sidedistx = 0;
	C->CS->sidedisty = 0;
	C->CS->deltadistx = 0;
	C->CS->deltadisty = 0;
	C->CS->perpwalldist = 0;
	C->CS->size_max_x = 0;
	C->CS->x = 0;
	C->CS->frametime = 0;
	C->CS->move_speed = 0;
	C->CS->rotation_speed = 0;
	C->CS->old_dir_x = 0;
	C->CS->oldcam_plane_x = 0;
	C->CS->str = NULL;
	C->CS->mapx = 0;
	C->CS->mapy = 0;
	C->CS->step_x = 0;
	C->CS->step_y = 0;
	C->CS->hit = 0;
	C->CS->side = 0;
	C->CS->lineheight = 0;
	C->CS->drawstart = 0;
	C->CS->drawend = 0;
	C->CS->color = 0;
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
	C->up_c = 0;
	C->up_f = 0;
	C->kr = NULL;
	set_bmp(cub);
	C->B->yes = 0;
}

t_cub	*sj_cub_init_stuct(t_cub *cub)
{
	if (!(C = malloc(sizeof(t_cub)))
		|| !(C->K = malloc(sizeof(t_key)))
		|| !(C->CS = malloc(sizeof(t_recast)))
		|| !(C->SP = malloc(sizeof(t_sprite))))
	{
		sj_stderr_parsing(-16);
		ult_i_to_vii(0, cub);
		exit(EXIT_FAILURE);
	}
	return (C);
}
