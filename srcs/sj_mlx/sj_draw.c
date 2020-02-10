/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:39:10 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 15:16:07 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_draw(t_cub *cub)
{
	int 	i;
	int		texnum;
	float	wallx;
	float	step;
	float	texpos;
	int		texx;
	int		texy;

	i = 0;
	while (i < C->C->drawstart)
	{
		C->img_data[i * C->res_x + (int)C->C->x] =
			sj_color(C->f_color_r, C->f_color_g, C->f_color_b);
		i++;
	}

	/*~ GO IN FUNCTION ~*/
	texnum = C->C->side;
	if (C->C->side == 0)
		wallx = C->C->pos_y + C->C->perpwalldist * C->C->raydir_y;
	else
		wallx = C->C->pos_x + C->C->perpwalldist * C->C->raydir_y;
	wallx -= floorf(wallx);
	texx = (int)(wallx * (float)C->xpm_x[C->C->side]);
	if (C->C->side == 0 && C->C->raydir_x > 0)
		texx = C->xpm_x[texnum] - texx - 1;
	if (C->C->side == 1 && C->C->raydir_x < 0)
		texx = C->xpm_x[texnum] - texx - 1;
	step = 1.0 * C->xpm_y[texnum] / C->C->lineheight;
	texpos = (C->C->drawstart - HEIGHT / 2 + C->C->lineheight / 2) * step;
	/*~                ~*/

	while (C->C->drawstart < C->C->drawend)
	{

		texy = (int)texpos & (C->xpm_y[texnum] - 1);
		texpos += step;
		C->img_data[C->C->drawstart++ * C->res_x + (int)C->C->x] =
			C->xpm_txt[texnum][C->xpm_y[texnum] * texy + texx];
	}
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
