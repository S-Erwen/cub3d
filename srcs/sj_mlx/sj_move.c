/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:50:08 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/02 21:32:23 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

void	sj_key_mv_right(t_cub *cub)
{
	float		x;
	float		y;

	x = C->CS->pos_x + C->CS->dir_y * C->CS->move_speed / 2;
	y = C->CS->pos_y;
	if (C->tab_map[(int)(y)][(int)x] == '0'
		|| C->tab_map[(int)(y)][(int)x] == C->pos)
		C->CS->pos_x += C->CS->dir_y * C->CS->move_speed / 2;
	y = C->CS->pos_y - C->CS->dir_x * C->CS->move_speed / 2;
	x = C->CS->pos_x;
	if (C->tab_map[(int)(y)][(int)x] == '0'
		|| C->tab_map[(int)(y)][(int)x] == C->pos)
		C->CS->pos_y -= C->CS->dir_x * C->CS->move_speed / 2;
}

void	sj_key_mv_left(t_cub *cub)
{
	float		x;
	float		y;

	x = C->CS->pos_x - C->CS->dir_y * C->CS->move_speed / 2;
	y = C->CS->pos_y;
	if (C->tab_map[(int)(y)][(int)x] == '0'
		|| C->tab_map[(int)(y)][(int)x] == C->pos)
		C->CS->pos_x -= C->CS->dir_y * C->CS->move_speed / 2;
	y = C->CS->pos_y + C->CS->dir_x * C->CS->move_speed / 2;
	x = C->CS->pos_x;
	if (C->tab_map[(int)(y)][(int)x] == '0'
		|| C->tab_map[(int)(y)][(int)x] == C->pos)
		C->CS->pos_y += C->CS->dir_x * C->CS->move_speed / 2;
}

void	sj_key_up(t_cub *cub)
{
	int		x;
	int		y;

	x = (int)(C->CS->pos_x + C->CS->dir_x * C->CS->move_speed);
	y = (int)(C->CS->pos_y);
	if (C->tab_map[y][x] == '0' || C->tab_map[y][x] == C->pos)
		C->CS->pos_x += C->CS->dir_x * C->CS->move_speed;
	x = (int)C->CS->pos_x;
	y = (int)(C->CS->pos_y + C->CS->dir_y * 0.06);
	if (C->tab_map[y][x] == '0' || C->tab_map[y][x] == C->pos)
		C->CS->pos_y += C->CS->dir_y * C->CS->move_speed;
}

void	sj_key_down(t_cub *cub)
{
	int		x;
	int		y;

	x = (int)(C->CS->pos_x - C->CS->dir_x * C->CS->move_speed);
	y = (int)(C->CS->pos_y);
	if (C->tab_map[y][x] == '0' || C->tab_map[y][x] == C->pos)
		C->CS->pos_x -= C->CS->dir_x * C->CS->move_speed;
	x = (int)(C->CS->pos_x);
	y = (int)(C->CS->pos_y - C->CS->dir_y * 0.06);
	if (C->tab_map[y][x] == '0' || C->tab_map[y][x] == C->pos)
		C->CS->pos_y -= C->CS->dir_y * C->CS->move_speed;
}
