/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_triforsprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 04:05:24 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:19:48 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_tab_sprite(t_cub *cub)
{
	int			y;
	int			i;

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
	{
		sj_stderr_parsing_tho(-15);
		exit(EXIT_FAILURE);
	}
	sj_tab_spritew(cub);
	return (0);
}

void	sj_tab_spritew(t_cub *cub)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	x = 0;
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

void	sj_tri(float tab[], int tab2[], int size)
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
