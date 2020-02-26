/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 05:04:56 by esidelar          #+#    #+#             */
/*   Updated: 2020/02/26 05:08:59 by esidelar         ###   ########lyon.fr   */
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

void	sj_tri(float tab[], int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
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
	sj_tri(spritex, i);
	sj_tri((float *)spritey, i);
	i = 0;
	while (i < C->SP->nb_sp)
	{
		sprite_dist[i] = spritex[C->SP->nb_sp - i - 1];
		dprintf(2, "sprite_dist[%d] = [%f]\n", i, sprite_dist[i]);
		spriteorder[i] = spritey[C->SP->nb_sp - i - 1];
		i++;
	}
	dprintf(2, "------------------------\n\n");
}

void	sj_sprite(t_cub *cub)
{
	int				spriteorder[50];
	float			sprite_dist[50];
	int				i;
	int				y;
	int				z;
	double			sprite_x = 0.0;
    double			sprite_y = 0.0;
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

	if (sj_tab_sprite(cub))
	{
		sj_stderr_parsing_tho(-15);
		exit(EXIT_FAILURE);
	}
	i = 0;
	z = 0;
	while (i < C->SP->nb_sp)
	{
		spriteorder[i] = i;
		sprite_dist[i] = pow(C->CS->pos_x - C->SP->x[i], 2) +
			pow(C->CS->pos_y - C->SP->y[i], 2);
		i++;
	}
	dprintf(2, "pos_x = [%f]\n", C->CS->pos_x);
	dprintf(2, "pos_y = [%f]\n\n", C->CS->pos_y);
	i = 0;
	// dprintf(2, "BEF = sprite_dist = [%f]\n", sprite_dist[0]);
	// dprintf(2, "BEF = sprite_dist = [%f]\n", sprite_dist[1]);
	sj_sort_sprites(spriteorder, sprite_dist, cub);
	// dprintf(2, "sprite_dist = [%f]\n", sprite_dist[0]);
	// dprintf(2, "sprite_dist = [%f]\n\n", sprite_dist[1]);
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
		spriteheight = abs((int)(C->res_y / transform_y));
		spritewidth = abs((int)(C->res_y / transform_y));
		draw_start_y = -spriteheight / 2 + C->res_y / 2;
		draw_end_y = spriteheight / 2 + C->res_y / 2;
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
					d = (y) * 256 - C->res_y * 128 + spriteheight
						* 128;
					tex_y = ((d * tex_height) / spriteheight) / 256;
					color = C->SP->txt_sp[tex_width * tex_y + tex_x];
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
}
