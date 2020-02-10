/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/30 11:50:08 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:52 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_key_mv_right(t_cub *cub)
{
	float		x;
	float		y;

	x = C->C->pos_x + C->C->dir_y * C->C->move_speed;
	y = C->C->pos_y;
	if (C->tab_map[(int)(y + 0.00001)][(int)x] != '1'
		&& C->tab_map[(int)(y - 0.00001)][(int)x] != '1')
		C->C->pos_x += C->C->dir_y * C->C->move_speed;
	y = C->C->pos_y - C->C->dir_x * C->C->move_speed;
	x = C->C->pos_x;
	if (C->tab_map[(int)y][(int)(x + 0.00001)] != '1'
		&& C->tab_map[(int)y][(int)(x - 0.00001)] != '1')
		C->C->pos_y -= C->C->dir_x * C->C->move_speed;
}

void	sj_key_mv_left(t_cub *cub)
{
	float		x;
	float		y;

	x = C->C->pos_x - C->C->dir_y * C->C->move_speed;
	y = C->C->pos_y;
	if (C->tab_map[(int)(y - 0.00001)][(int)x] != '1'
		&& C->tab_map[(int)(y + 0.00001)][(int)x] != '1')
		C->C->pos_x -= C->C->dir_y * C->C->move_speed;
	y = C->C->pos_y + C->C->dir_x * C->C->move_speed;
	x = C->C->pos_x;
	if (C->tab_map[(int)y][(int)(x + 0.00001)] != '1'
		&& C->tab_map[(int)y][(int)(x - 0.00001)] != '1')
		C->C->pos_y += C->C->dir_x * C->C->move_speed;
}

void	sj_key_up(t_cub *cub)
{
	int		x;
	int		y;

	x = (int)(C->C->pos_x + C->C->dir_x * C->C->move_speed);
	y = (int)(C->C->pos_y);
	if (C->tab_map[y][x] != '1' || C->tab_map[y][x] == C->pos)
		C->C->pos_x += C->C->dir_x * C->C->move_speed;
	x = (int)C->C->pos_x;
	y = (int)(C->C->pos_y + C->C->dir_y * 0.06);
	if (C->tab_map[y][x] != '1' || C->tab_map[y][x] == C->pos)
		C->C->pos_y += C->C->dir_y * C->C->move_speed;
}

void	sj_key_down(t_cub *cub)
{
	int		x;
	int		y;

	x = (int)(C->C->pos_x - C->C->dir_x * C->C->move_speed);
	y = (int)(C->C->pos_y);
	if (C->tab_map[y][x] != '1' || C->tab_map[y][x] == C->pos)
		C->C->pos_x -= C->C->dir_x * C->C->move_speed;
	x = (int)(C->C->pos_x);
	y = (int)(C->C->pos_y - C->C->dir_y * 0.06);
	if (C->tab_map[y][x] != '1' || C->tab_map[y][x] == C->pos)
		C->C->pos_y -= C->C->dir_y * C->C->move_speed;
}
