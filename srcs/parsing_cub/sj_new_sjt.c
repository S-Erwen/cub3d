/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_new_sjt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:02:13 by esidelar          #+#    #+#             */
/*   Updated: 2020/07/22 15:30:37 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_fck_new_sujet_check(t_cub *cub, int len)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (C->tab_map[i])
	{
		if ((C->rut = sj_check_updown(C->rut, len, cub, i)) < 0)
			return (C->rut);
		i++;
	}
	i = 0;
	if ((i = sj_zero_itsok(i, y, cub)) < 0)
		return (i);
	while (i)
		free(C->kr_tab[i--]);
	C->kr_tab[i] = sj_free(C->kr_tab[i]);
	free(C->kr_tab);
	return (0);
}

int		sj_ckeck_first_end(t_cub *cub, int i, int len)
{
	int		y;

	y = 0;
	while (y < len)
	{
		if (C->kr_tab[0][y] == ' ' && C->kr_tab[1][y + 1] == '0')
			return (-12);
		if (y != 0 && C->kr_tab[0][y] == ' ' && C->kr_tab[1][y - 1] == '0')
			return (-12);
		y++;
	}
	y = 0;
	while (y < len)
	{
		if (C->kr_tab[i][y] == ' ' && C->kr_tab[i - 1][y + 1] == '0')
			return (-12);
		if (y != 0 && C->kr_tab[i][y] == ' ' && C->kr_tab[i - 1][y - 1] == '0')
			return (-12);
		y++;
	}
	return (0);
}
