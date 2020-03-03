/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:04:56 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/03 06:40:09 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

int		sj_tab_sprite(t_cub *cub)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	while (C->line_map[y])
	{
		if (C->line_map[y] == '2')
			i++;
		y++;
	}
	C->SP->nb_sp = i;
	if (!(C->SP->y = malloc(sizeof(int) * (i)))
		|| !(C->SP->x = malloc(sizeof(int) * (i))))
		return (-1);
	i = 0;
	y = 0;
	while (C->tab_map[y])
	{
		while (C->tab_map[y][x])
		{
			if (C->tab_map[y][x] == '2')
			{
				C->SP->y[i] = y;
				C->SP->x[i++] = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	sj_tri(float tab[], int tab2[],int size)
{
	int		i;
	float	temp;
	int		temp2;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			temp2 = tab2[i];
			tab2[i] = tab2[i + 1];
			tab2[i + 1] = temp2;
			i = -1;
		}
		i++;
	}
}

void	sj_sort_sprites(int spriteorder[], float sprite_dist[], t_cub *cub)
{
	float		spritex[C->SP->nb_sp];
	int			spritey[C->SP->nb_sp];
	int			i;

	i = 0;
	while (i < C->SP->nb_sp)
	{
		spritex[i] = sprite_dist[i];
		spritey[i] = spriteorder[i];
		i++;
	}
	sj_tri(spritex, spritey, i);
	i = 0;
	while (i < C->SP->nb_sp)
	{
		sprite_dist[i] = spritex[C->SP->nb_sp - i - 1];
		spriteorder[i] = spritey[C->SP->nb_sp - i - 1];
		i++;
	}
}

void	sj_sprite(t_cub *cub)
{
	if (sj_tab_sprite(cub))
	{
		sj_stderr_parsing_tho(-15);
		exit(EXIT_FAILURE);
	}

	int				spriteorder[C->SP->nb_sp];
	float			sprite_dist[C->SP->nb_sp];
	int				i;
	int				y;
	int				z;
	float			sprite_x;
    float			sprite_y;
	float			invdet;
	float			transform_x;
	float			transform_y;
	int				sprite_screenx;
	int				spriteheight;
	int				spritewidth;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				tex_width = C->SP->x_sp;
	int				tex_height = C->SP->y_sp;
	int				d;
	unsigned int	color;

	i = 0;
	z = 0;
  	while (i < C->SP->nb_sp)
	{
		spriteorder[i] = i;
		sprite_dist[i] = pow(C->CS->pos_x - C->SP->x[i], 2) +
			pow(C->CS->pos_y - C->SP->y[i], 2);
		i++;
	}
	sj_sort_sprites(spriteorder, sprite_dist, cub);
	while (z < C->SP->nb_sp)
	{
		sprite_x = C->SP->x[spriteorder[z]] - C->CS->pos_x + 0.5;
		sprite_y = C->SP->y[spriteorder[z]] - C->CS->pos_y + 0.5;
		invdet = 1 / (C->CS->cam_plane_x * C->CS->dir_y - C->CS->dir_x *
			C->CS->cam_plane_y);
		transform_x = invdet * (C->CS->dir_y * sprite_x - C->CS->dir_x * sprite_y);
		transform_y = invdet * (-C->CS->cam_plane_y * sprite_x +
			C->CS->cam_plane_x * sprite_y);
		sprite_screenx = (int)((C->res_x / 2) * (1 + transform_x / transform_y));
		spriteheight = abs((int)(C->HEIGHT / transform_y));
		spritewidth = abs((int)(C->HEIGHT / transform_y));
		draw_start_y = -spriteheight / 2 + C->HEIGHT / 2;
		draw_end_y = spriteheight / 2 + C->HEIGHT / 2;
		draw_start_x = -spritewidth / 2 + sprite_screenx;
		draw_end_x = spritewidth / 2 + sprite_screenx;
		if (draw_start_y < 0)
			draw_start_y = 0;
		if (draw_end_y >= C->res_y)
			draw_end_y = C->res_y - 1;
		if (draw_start_x < 0)
			draw_start_x = 0;
		if (draw_end_x >= C->res_x)
			draw_end_x = C->res_x;
		i = draw_start_x;
		while (i < draw_end_x)
		{
			tex_x = (int)(256 * (i - (-spritewidth / 2 + sprite_screenx))
				* tex_width / spritewidth) / 256;
			y = draw_start_y;
			if (transform_y > 0 && i > 0 && i < C->res_x && transform_y
				< C->SP->zbuffer[i])
			{
				while (y < draw_end_y)
				{
					d = (y) * 256 - C->HEIGHT * 128 + spriteheight
						* 128;
					tex_y = ((d * tex_height) / spriteheight) / 256;
					if ((tex_width * tex_y + tex_x) > C->SP->size)
						color = C->SP->txt_sp[tex_width * tex_y + tex_x];
					else
						color = 0;
					if (color > 0 && color & 0x00FFFFFF)
						C->img_data[y * C->res_x + i] =
							color;
					y++;
				}
			}
			i++;
		}
		z++;
	}
	free(C->SP->x);
	free(C->SP->y);
}
