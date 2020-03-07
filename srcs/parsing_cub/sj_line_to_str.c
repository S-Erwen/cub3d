/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_line_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:08:20 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/07 21:44:00 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*sj_line_to_str(char *line, char *str, int i, int y)
{
	while (line[i])
	{
		while (line[i] == ' ' && line[i + 1] == ' ')
		{
			str[y++] = '1';
			i += 2;
		}
		if (line[i] == '1' || line[i] == '0' || line[i] == '2'
			|| line[i] == 'N' || line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'S')
			str[y++] = line[i++];
		else if (line[i] == ' ')
			return (NULL);
		if (line[i] != ' ' && line[i])
			return (NULL);
		if (line[i])
			i++;
	}
	str[y] = '\0';
	return (str);
}

int		sj_check_spcline(t_cub *cub, int i)
{
	int	y;

	y = 0;
	while (C->tab_map[i][y])
	{
		if (y > 1 && (C->tab_map[i][y] == '0' || C->tab_map[i][y] == '1')
			&& C->tab_map[i][y - 2] == ' ')
		{
			if (C->tab_map[i][y] == '0')
				return (-12);
		}
		y++;
	}
	return (0);
}
