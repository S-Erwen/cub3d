/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_addchr_for_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:17:55 by esidelar          #+#    #+#             */
/*   Updated: 2020/07/22 15:25:10 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sj_newline(t_cub *cub)
{
	int		i;

	i = 0;
	C->line_map = sj_free(C->line_map);
	C->line_map = ft_strdup(C->tab_map[i++]);
	C->line_map = ft_add_char(C->line_map, '\n');
	while (C->tab_map[i])
	{
		C->line_map = ft_strjoin_with_free(C->line_map, C->tab_map[i++], 1);
		C->line_map = ft_add_char(C->line_map, '\n');
	}
}

int		sj_fck_new_sujet(t_cub *cub)
{
	size_t	len;
	int		i;
	int		ret;

	i = 0;
	C->rut = 0;
	C->kr_tab = ft_split(C->kr, '\n');
	C->kr = sj_free(C->kr);
	len = sj_count_new_sujet(cub);
	sj_add_for_kr(cub, len);
	while (C->kr_tab[i])
		i++;
	if ((ret = sj_ckeck_first_end(cub, i - 1, len)) < 0)
		return (ret);
	return (sj_fck_new_sujet_check(cub, len));
}

int		sj_cmp_end(t_cub *cub, int *i, size_t len)
{
	while (ft_strlen(C->tab_map[*i]) < len)
		C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
	return (0);
}

int		sj_cmp_ud(t_cub *cub, int *i, size_t len, int bool)
{
	int	y;

	if (bool)
	{
		while (ft_strlen(C->tab_map[*i]) < ft_strlen(C->tab_map[*i + 1]))
		{
			if (C->tab_map[*i + 1][ft_strlen(C->tab_map[*i])] == '0')
				return (-12);
			C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
		}
		while (ft_strlen(C->tab_map[*i]) < len)
			C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
		return (0);
	}
	y = ft_strlen(C->tab_map[*i + 1]);
	while (C->tab_map[*i][y])
	{
		if (C->tab_map[*i][y] == '0')
			return (-12);
		y++;
	}
	while (ft_strlen(C->tab_map[*i]) < len)
		C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
	return (0);
}

size_t	sj_count_new_sujet(t_cub *cub)
{
	size_t	max;
	int		i;

	i = 0;
	max = 0;
	while (C->tab_map[i])
	{
		if (ft_strlen(C->tab_map[i]) > max)
			max = ft_strlen(C->tab_map[i++]);
		else
			i++;
	}
	return (max);
}
