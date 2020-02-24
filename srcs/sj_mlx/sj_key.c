/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/09 04:45:00 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:52 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_key_press(int key, t_cub *cub)
{
	if (key == L_LEFT)
		C->key->mv_left = 1;
	if (key == L_RIGHT)
		C->key->mv_right = 1;
	if (key == L_DOWN || key == R_DOWN)
		C->key->down = 1;
	if (key == R_RIGHT)
		C->key->right = 1;
	if (key == R_LEFT)
		C->key->left = 1;
	if (key == L_UP || key == R_UP)
		C->key->up = 1;
	if (key == ESCAPE)
		exit(EXIT_SUCCESS);
	return (0);
}

int		sj_key_release(int key, t_cub *cub)
{
	if (key == L_LEFT)
		C->key->mv_left = 0;
	if (key == L_RIGHT)
		C->key->mv_right = 0;
	if (key == L_DOWN || key == R_DOWN)
		C->key->down = 0;
	if (key == R_RIGHT)
		C->key->right = 0;
	if (key == R_LEFT)
		C->key->left = 0;
	if (key == L_UP || key == R_UP)
		C->key->up = 0;
	return (0);
}
