/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parsing_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 07:10:54 by esidelar          #+#    #+#             */
/*   Updated: 2020/07/29 06:25:03 by esidelar         ###   ########lyon.fr   */
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
	C->res_x = ft_atol(line + i);
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	C->res_y = ft_atol(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i])
		if (line[i++] != ' ')
			return (-1);
	if (C->res_x <= 0 || C->res_y <= 0)
		return (-1);
	if (C->res_x >= INT_MAX)
		C->res_x = 1920;
	if (C->res_y >= INT_MAX)
		C->res_y = 1080;
	return (1);
}
