/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:39:10 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:05:41 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_draw(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < C->CS->drawstart)
	{
		C->img_data[i * C->res_x + (int)C->CS->x] =
			sj_color(C->f_color_r, C->f_color_g, C->f_color_b);
		i++;
	}
	sj_draw_texture(cub);
	i = C->CS->drawend;
	while (i < C->res_y - 1)
	{
		C->img_data[i * C->res_x + (int)C->CS->x] =
			sj_color(C->c_color_r, C->c_color_g, C->c_color_b);
		i++;
	}
}

void	sj_draw_start_end(t_cub *cub)
{
	if (C->CS->side == 0 || C->CS->side == 1)
		C->CS->perpwalldist = (C->CS->mapx - C->CS->pos_x +
			(1 - C->CS->step_x) / 2) / C->CS->raydir_x;
	else
		C->CS->perpwalldist = (C->CS->mapy - C->CS->pos_y +
			(1 - C->CS->step_y) / 2) / C->CS->raydir_y;
	C->CS->lineheight = (long int)(C->height / C->CS->perpwalldist);
	C->CS->drawstart = -C->CS->lineheight / 2 + C->height / 2;
	if (C->CS->drawstart < 0)
		C->CS->drawstart = 0;
	C->CS->drawend = C->CS->lineheight / 2 + C->height / 2;
	if (C->CS->drawend >= C->res_y)
		C->CS->drawend = C->res_y - 1;
}

void	sj_draw_texture(t_cub *cub)
{
	C->texnum = C->CS->side;
	if (C->CS->side == 0 || C->CS->side == 1)
		C->wallx = C->CS->pos_y + C->CS->perpwalldist * C->CS->raydir_y;
	else
		C->wallx = C->CS->pos_x + C->CS->perpwalldist * C->CS->raydir_x;
	C->wallx -= floorf(C->wallx);
	C->texx = (int)(C->wallx * (float)C->xpm_x[C->CS->side]);
	if (C->CS->side == 0 && C->CS->raydir_x > 0)
		C->texx = C->xpm_x[C->texnum] - C->texx - 1;
	if (C->CS->side == 1 && C->CS->raydir_x < 0)
		C->texx = C->xpm_x[C->texnum] - C->texx - 1;
	C->step = 1.0 * C->xpm_y[C->texnum] / C->CS->lineheight;
	C->texpos = (C->CS->drawstart - C->height / 2 + C->CS->lineheight / 2) *
		C->step;
	while (C->CS->drawstart < C->CS->drawend)
	{
		C->texy = (int)C->texpos;
		C->texpos += C->step;
		C->img_data[C->CS->drawstart++ * C->res_x + (int)C->CS->x] =
			C->xpm_txt[C->texnum][C->xpm_x[C->texnum] * C->texy + C->texx];
	}
}
