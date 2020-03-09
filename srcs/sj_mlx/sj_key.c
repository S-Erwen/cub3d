/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:45:00 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/09 08:33:14 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

int		sj_key_press(int key, t_cub *cub)
{
	if (key == L_LEFT)
		C->K->mv_left = 1;
	if (key == L_RIGHT)
		C->K->mv_right = 1;
	if (key == L_DOWN || key == R_DOWN)
		C->K->down = 1;
	if (key == R_RIGHT)
		C->K->right = 1;
	if (key == R_LEFT)
		C->K->left = 1;
	if (key == L_UP || key == R_UP)
		C->K->up = 1;
	if (key == ESCAPE)
	{
		ult_i_to_vii(-99, cub);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		sj_key_release(int key, t_cub *cub)
{
	if (key == L_LEFT)
		C->K->mv_left = 0;
	if (key == L_RIGHT)
		C->K->mv_right = 0;
	if (key == L_DOWN || key == R_DOWN)
		C->K->down = 0;
	if (key == R_RIGHT)
		C->K->right = 0;
	if (key == R_LEFT)
		C->K->left = 0;
	if (key == L_UP || key == R_UP)
		C->K->up = 0;
	return (0);
}
