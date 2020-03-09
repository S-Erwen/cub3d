/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parsing_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 07:10:54 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/09 02:19:59 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_r(char *line, t_cub *cub)
{
	int	i;

	i = sj_space_skip(line);
	if (line[i] == 'R')
		return (sj_res(line, cub, i));
	return (0);
}

int		sj_res(char *line, t_cub *cub, int i)
{
	if (C->res_x || C->res_y)
		return (-10);
	i++;
	while (line[i] && line[i] == ' ')
		i++;
	C->res_x = ft_atoi(line + i);
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	C->res_y = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i])
		if (line[i++] != ' ')
			return (-1);
	if (C->res_x <= 0 || C->res_y <= 0)
		return (-1);
	return (1);
}
