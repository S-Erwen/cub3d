/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:39:10 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 05:31:04 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_draw(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->cast->drawstart)
	{
		cub->img_data[i * cub->res_x + (int)cub->cast->x] =
			sj_color(cub->f_color_r, cub->f_color_g, cub->f_color_b);
		i++;
	}
	while (cub->cast->drawstart < cub->cast->drawend)
		cub->img_data[cub->cast->drawstart++ * cub->res_x +
			(int)cub->cast->x] = cub->xpm_x[0]++;
	i = cub->cast->drawend;
	while (i < cub->res_y - 1)
	{
		cub->img_data[i * cub->res_x + (int)cub->cast->x] =
			sj_color(cub->c_color_r, cub->c_color_g, cub->c_color_b);
		i++;
	}
	cub->cast->x++;
}

void	sj_draw_start_end(t_cub *cub)
{
	if (cub->cast->side == 0 || cub->cast->side == 1)
		cub->cast->perpwalldist = (cub->cast->mapx - cub->cast->pos_x +
			(1 - cub->cast->stepX) / 2) / cub->cast->raydir_x;
	else
		cub->cast->perpwalldist = (cub->cast->mapy - cub->cast->pos_y +
			(1 - cub->cast->stepY) / 2) / cub->cast->raydir_y;
	cub->cast->lineheight = (long int)(HEIGHT / cub->cast->perpwalldist);
	cub->cast->drawstart = -cub->cast->lineheight / 2 + HEIGHT / 2;
	if (cub->cast->drawstart < 0)
		cub->cast->drawstart = 0;
	cub->cast->drawend = cub->cast->lineheight / 2 + HEIGHT / 2;
	if (cub->cast->drawend >= cub->res_y)
		cub->cast->drawend = cub->res_y - 1;
	cub->cast->color = OXRED;
	if (cub->cast->side == 1)
		cub->cast->color = OXBLUE;
	if (cub->cast->side == 2)
		cub->cast->color = OXYELLOW;
	if (cub->cast->side == 3)
		cub->cast->color = OXMAGENTA;
}
