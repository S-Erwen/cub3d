/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:39:10 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 17:39:21 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_draw(t_cub *cub)
{
	int 	i;

	i = 0;
	while (i < C->C->drawstart)
	{
		C->img_data[i * C->res_x + (int)C->C->x] =
			sj_color(C->f_color_r, C->f_color_g, C->f_color_b);
		i++;
	}
	sj_draw_texture(cub);
	i = C->C->drawend;
	while (i < C->res_y - 1)
	{
		C->img_data[i * C->res_x + (int)C->C->x] =
			sj_color(C->c_color_r, C->c_color_g, C->c_color_b);
		i++;
	}
	C->C->x++;
}

void	sj_draw_start_end(t_cub *cub)
{
	if (C->C->side == 0 || C->C->side == 1)
		C->C->perpwalldist = (C->C->mapx - C->C->pos_x +
			(1 - C->C->stepX) / 2) / C->C->raydir_x;
	else
		C->C->perpwalldist = (C->C->mapy - C->C->pos_y +
			(1 - C->C->stepY) / 2) / C->C->raydir_y;
	C->C->lineheight = (long int)(HEIGHT / C->C->perpwalldist);
	C->C->drawstart = -C->C->lineheight / 2 + HEIGHT / 2;
	if (C->C->drawstart < 0)
		C->C->drawstart = 0;
	C->C->drawend = C->C->lineheight / 2 + HEIGHT / 2;
	if (C->C->drawend >= C->res_y)
		C->C->drawend = C->res_y - 1;
}

void	sj_draw_texture(t_cub *cub)
{
	C->texnum = C->C->side;
	if (C->C->side == 0)
		C->wallx = C->C->pos_y + C->C->perpwalldist * C->C->raydir_y;
	else
		C->wallx = C->C->pos_y + C->C->perpwalldist * C->C->raydir_y;
	C->wallx -= floorf(C->wallx);
	C->texx = (int)(C->wallx * (float)C->xpm_x[C->C->side]);
	if (C->C->side == 0 && C->C->raydir_x > 0)
		C->texx = C->xpm_x[C->texnum] - C->texx - 1;
	if (C->C->side == 1 && C->C->raydir_x < 0)
		C->texx = C->xpm_x[C->texnum] - C->texx - 1;
	C->step = 1.0 * C->xpm_y[C->texnum] / C->C->lineheight;
	C->texpos = (C->C->drawstart - HEIGHT / 2 + C->C->lineheight / 2) * C->step;
	while (C->C->drawstart < C->C->drawend)
	{
		C->texy = (int)C->texpos & (C->xpm_y[C->texnum] - 1);
		C->texpos += C->step;
		C->img_data[C->C->drawstart++ * C->res_x + (int)C->C->x] =
			C->xpm_txt[C->texnum][C->xpm_y[C->texnum] * C->texy + C->texx];
	}
}
