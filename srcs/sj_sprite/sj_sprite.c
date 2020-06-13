/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:04:56 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:19:17 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_sprite(t_cub *cub)
{
	int				spriteorder[C->SP->nb_sp];
	float			sprite_dist[C->SP->nb_sp];

	C->SP->i = 0;
	C->SP->z = 0;
	C->SP->tex_width = C->SP->x_sp;
	C->SP->tex_height = C->SP->y_sp;
	while (C->SP->i < C->SP->nb_sp)
	{
		spriteorder[C->SP->i] = C->SP->i;
		sprite_dist[C->SP->i] = pow(C->CS->pos_x - C->SP->x[C->SP->i], 2) +
			pow(C->CS->pos_y - C->SP->y[C->SP->i], 2);
		C->SP->i++;
	}
	sj_sort_sprites(spriteorder, sprite_dist, cub);
	while (C->SP->z < C->SP->nb_sp)
		sj_sp_cnt(cub, spriteorder);
	free(C->SP->x);
	free(C->SP->y);
}

void	sj_pave_one(t_cub *cub, int *spriteorder)
{
	C->SP->sprite_x = C->SP->x[spriteorder[C->SP->z]] - C->CS->pos_x + 0.5;
	C->SP->sprite_y = C->SP->y[spriteorder[C->SP->z]] - C->CS->pos_y + 0.5;
	C->SP->invdet = 1 / (C->CS->cam_plane_x * C->CS->dir_y - C->CS->dir_x *
		C->CS->cam_plane_y);
	C->SP->transform_x = C->SP->invdet * (C->CS->dir_y * C->SP->sprite_x -
		C->CS->dir_x * C->SP->sprite_y);
	C->SP->transform_y = C->SP->invdet * (-C->CS->cam_plane_y *
		C->SP->sprite_x + C->CS->cam_plane_x * C->SP->sprite_y);
	C->SP->sprite_screenx = (int)((C->res_x / 2) * (1 + C->SP->transform_x /
		C->SP->transform_y));
	C->SP->spriteheight = abs((int)(C->HEIGHT / C->SP->transform_y));
	C->SP->spritewidth = abs((int)(C->HEIGHT / C->SP->transform_y));
	C->SP->draw_start_y = -C->SP->spriteheight / 2 + C->HEIGHT / 2;
	C->SP->draw_end_y = C->SP->spriteheight / 2 + C->HEIGHT / 2;
	C->SP->draw_start_x = -C->SP->spritewidth / 2 + C->SP->sprite_screenx;
	C->SP->draw_end_x = C->SP->spritewidth / 2 + C->SP->sprite_screenx;
	if (C->SP->draw_start_y < 0)
		C->SP->draw_start_y = 0;
	if (C->SP->draw_end_y >= C->res_y)
		C->SP->draw_end_y = C->res_y - 1;
	if (C->SP->draw_start_x < 0)
		C->SP->draw_start_x = 0;
	if (C->SP->draw_end_x >= C->res_x)
		C->SP->draw_end_x = C->res_x;
}

void	sj_pave_two(t_cub *cub)
{
	if (C->SP->transform_y > 0 && C->SP->i > 0 && C->SP->i < C->res_x
		&& C->SP->transform_y < C->SP->zbuffer[C->SP->i])
	{
		while (C->SP->j < C->SP->draw_end_y)
		{
			C->SP->d = (C->SP->j) * 256 - C->HEIGHT * 128 + C->SP->spriteheight
				* 128;
			C->SP->tex_y = ((C->SP->d * C->SP->tex_height) /
				C->SP->spriteheight) / 256;
			if ((C->SP->tex_width * C->SP->tex_y + C->SP->tex_x)
				> C->SP->size)
				C->SP->color = C->SP->txt_sp[C->SP->tex_width *
					C->SP->tex_y + C->SP->tex_x];
			else
				C->SP->color = 0;
			if (C->SP->color > 0 && C->SP->color & 0x00FFFFFF)
			{
				C->img_data[C->SP->j * C->res_x + C->SP->i] =
					C->SP->color;
			}
			C->SP->j++;
		}
	}
}

void	sj_sp_cnt(t_cub *cub, int *spriteorder)
{
	sj_pave_one(cub, spriteorder);
	C->SP->i = C->SP->draw_start_x;
	while (C->SP->i < C->SP->draw_end_x)
	{
		C->SP->tex_x = (int)(256 * (C->SP->i - (-C->SP->spritewidth / 2 +
			C->SP->sprite_screenx)) * C->SP->tex_width /
			C->SP->spritewidth) / 256;
		C->SP->j = C->SP->draw_start_y;
		sj_pave_two(cub);
		C->SP->i++;
	}
	C->SP->z++;
}
