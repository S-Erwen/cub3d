/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_sprite.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sanjaro <sanjaro@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 05:04:56 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/23 10:01:08 by sanjaro     ###    #+. /#+    ###.fr     */
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
	int				vmovescreen;
	int				spriteheight;
	int				spritewidth;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				tex_width = 64;
	int				tex_height = 64;
	int				d;
	unsigned int	color;

	sj_tab_sprite(cub);
	i = 0;
	while (i < C->SP->nb_sp)
	{
		spriteorder[i] = i;
		sprite_dist[i] = pow(C->CS->pos_x - C->SP->x[i], 2) +
			pow(C->CS->pos_y - C->SP->y[i], 2);
		i++;
	}
	sj_sort_sprites(spriteorder, sprite_dist, cub);
	i = 0;
	while (i < C->SP->nb_sp)
	{
		sprite_x = C->SP->x[spriteorder[i]] - C->CS->pos_x + 0.5;
		sprite_y = C->SP->y[spriteorder[i]] - C->CS->pos_y + 0.5;
		i++;
	}
	invdet = 1 / (C->CS->cam_plane_x * C->CS->dir_y - C->CS->dir_x *
		C->CS->cam_plane_y);
	transform_x = invdet * (C->CS->dir_y * sprite_x - C->CS->dir_x * sprite_y);
	transform_y = invdet * (-C->CS->cam_plane_y * sprite_x +
		C->CS->cam_plane_x * sprite_y);
	sprite_screenx = (int)((C->res_x / 2) * (1 + transform_x / transform_y));
	vmovescreen = (int)(VMOVE / transform_y);
	spriteheight = sj_abs((int)(C->height / transform_y)) / VDIV;
	spritewidth = sj_abs((int)(C->height / transform_y)) / UDIV;
	draw_start_y = -spriteheight / 2 + C->res_y / 2 + vmovescreen;
	draw_end_y = spriteheight / 2 + C->res_y / 2 + vmovescreen;
	draw_start_x = -spritewidth / 2 + sprite_screenx;
	draw_end_x = spritewidth / 2 + sprite_screenx;
	if (draw_start_y < 0)
		draw_start_y = 0;
	if (draw_end_y >= C->res_y)
		draw_end_y = C->res_y - 1;
	if (draw_start_x < 0)
		draw_start_x = 0;
	if (draw_end_x >= C->res_x)
		draw_end_x = C->res_x - 1;
	i = draw_start_x;
	dprintf(2, "color = [%d]\n", i);
	while (i < draw_end_x)
	{
		tex_x = (int)((i - (-spritewidth / 2 + sprite_screenx))
			* tex_width / spritewidth);
		y = draw_start_y;
		if (transform_y > 0 && i > 0 && i < C->res_x && transform_y
			< C->SP->zbuffer[i])
			while (y < draw_end_y)
			{
				d = (y - vmovescreen) * 256 - C->res_y * 128 + spriteheight
					* 128;
				tex_y = ((d * tex_height) / spriteheight) / 256;
				color = C->SP->txt_sp[tex_height * tex_x + tex_y];
				if (color > 0 && color & 0x0FFFFF)
					C->img_data[y * C->res_x + i] =
						color;
				y++;
			}
		i++;
	}
}
