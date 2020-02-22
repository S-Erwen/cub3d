/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_sprite.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 05:04:56 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 02:14:57 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_tab_sprite(t_cub *cub)
{
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	while (C->tab_map[y])
	{
		while (C->tab_map[y][x])
		{
			if (C->tab_map[y][x] == '2')
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	C->SP->nb_sp = i;
	if (!(C->SP->y = malloc(sizeof(int) * (i))))
		return ;
	if (!(C->SP->x = malloc(sizeof(int) * (i))))
		return ;
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
}

void	sj_tri(float t[], int n) 
{
	int		i;
	int		j; 
	int		tmp;

	i = 1; 
	j = 0; 
	while (i)
	{
		i = 0;
		j = 0;
		while (j < n - 1)
		{
			if (t[j] > t[j + 1])
			{
 				tmp = t[j + 1];
 				t[j + 1] = t[j];
 				t[j] = tmp;
				i = 1;
 			}
			j++;
		}
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
		spriteorder[i] = spritey[C->SP->nb_sp - i - 1];
		i++;
	}
}

void	sj_sprite(t_cub *cub)
{
	int				spriteorder[C->SP->nb_sp];
	float			sprite_dist[C->SP->nb_sp];
	int				i;
	int				y;
	double			sprite_x = 0.0;
    double			sprite_y = 0.0;
	float			invdet;
	float			transform_x;
	float			transform_y;
	int				sprite_screenx;
	//int				vmove_screen;
	int				spriteheight;
	int				spritewidth;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				tex_width = 64;
	int				tex_height = 64;
	int				d;
	unsigned int	color;

	C->WIDTH = C->res_x / 1.35;
	sj_tab_sprite(cub);
	i = 0;
	while (i < C->SP->nb_sp)
	{
		spriteorder[i] = i;
		sprite_dist[i] = (((C->CS->pos_x - C->SP->x[i]) *
			(C->CS->pos_x - C->SP->x[i])) +
			((C->CS->pos_y - C->SP->y[i]) * (C->CS->pos_y - C->SP->y[i])));
		i++;
	}
	sj_sort_sprites(spriteorder, sprite_dist, cub);
	i = 0;
	while (i < C->SP->nb_sp)
	{
		sprite_x = C->SP->x[spriteorder[i]] - C->CS->pos_x;
		sprite_y = C->SP->y[spriteorder[i]] - C->CS->pos_y;
		i++;
	}
	invdet = 1.0 / (C->CS->cam_plane_x * C->CS->dir_y - C->CS->dir_x *
		C->CS->cam_plane_y);
	transform_x = invdet * (C->CS->dir_y * sprite_x - C->CS->dir_x * sprite_y);
	transform_y = invdet * (-C->CS->cam_plane_y * sprite_x +
		C->CS->cam_plane_x * sprite_y);
	sprite_screenx = (int)((C->HEIGHT / 2) * (1 + transform_x - transform_y));
	spriteheight = sj_abs((int)(C->WIDTH / transform_y));
	draw_start_y = -spriteheight / 2 + C->WIDTH / 2;
	if (draw_start_y < 0)
		draw_start_y = 0;
	draw_end_y = spriteheight / 2 + C->WIDTH / 2;
	if (draw_end_y >= C->WIDTH)
		draw_end_y = C->WIDTH - 1;
	spritewidth = sj_abs((int)(C->WIDTH / transform_y));
	draw_start_x = -spritewidth / 2 + sprite_screenx;
	if (draw_start_x < 0)
		draw_start_x = 0;
	draw_end_x = spritewidth / 2 + sprite_screenx;
	if (draw_end_x >= C->HEIGHT)
		draw_end_x = C->HEIGHT - 1;
	stripe = draw_start_x;
	while (stripe < draw_end_x)
	{
		tex_x = (int)((stripe - (-spritewidth / 2 + sprite_screenx)) * tex_width / spritewidth);
		y = draw_start_y;
		if (transform_y > 0 && stripe > 0 && stripe < C->width && transform_y < C->SP->zbuffer[stripe])
			while (y < draw_end_y)
			{
				d = (y) * 256 - C->WIDTH * 128 + spriteheight * 128;
				tex_y = ((d * tex_height) / spriteheight) / 256;
				color = C->SP->txt_sp[tex_width * tex_y + tex_x];
				if (color)
					C->img_data[y * C->res_y + stripe] = color;
				y++;
			}
		stripe++;
	}
}
