/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_map_add_fnrm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 04:06:29 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:06:32 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_check_updown(int ret, size_t len, t_cub *cub, int i)
{
	if (C->tab_map[i + 1])
	{
		if (ft_strlen(C->tab_map[i]) != len)
		{
			if (ft_strlen(C->tab_map[i]) > ft_strlen(C->tab_map[i + 1]))
				ret = sj_cmp_ud(cub, &i, len, 0);
			else
				ret = sj_cmp_ud(cub, &i, len, 1);
		}
	}
	else if (ft_strlen(C->tab_map[i]) != len)
		ret = sj_cmp_end(cub, &i, len);
	if (ret == -12)
		return (ret);
	return (0);
}

int		sj_gigaif(int i, int y, t_cub *cub)
{
	if ((C->kr_tab[i][y] == ' ' && ((C->tab_map[i - 1][y + 1] == '0')
		|| (C->tab_map[i - 1][y + 1] == '2')))
		|| (C->kr_tab[i][y] == ' ' && ((C->tab_map[i + 1][y + 1] == '0')
		|| (C->tab_map[i + 1][y + 1] == '2'))))
		return (-12);
	if (y > 0)
		if ((C->kr_tab[i][y] == ' ' && ((C->tab_map[i - 1][y - 1] == '0')
			|| (C->tab_map[i - 1][y - 1] == '2')))
			|| (C->kr_tab[i][y] == ' ' && ((C->tab_map[i + 1][y - 1] == '0')
			|| (C->tab_map[i + 1][y - 1] == '2'))))
			return (-12);
	return (0);
}

int		sj_zero_itsok(int i, int y, t_cub *cub)
{
	int ret;

	while (C->tab_map[i + 1])
	{
		if (i > 0)
		{
			y = 0;
			while (C->tab_map[i][y])
			{
				if ((ret = sj_gigaif(i, y, cub)) < 0)
					return (ret);
				y++;
			}
			y = 0;
			while (C->kr_tab[i][y] && C->tab_map[i - 1][y])
			{
				if (C->kr_tab[i][y] == ' ' && C->tab_map[i - 1][y] == '0')
					return (-12);
				y++;
			}
		}
		i++;
	}
	return (i);
}
