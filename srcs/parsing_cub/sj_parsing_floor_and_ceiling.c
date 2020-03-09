/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parsing_floor_and_ceiling.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 07:13:44 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/09 01:50:12 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_f(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'F')
	{
		if (C->up_f)
			return (-10);
		C->up_f = 1;
		if (sj_parse_f2(line, cub))
			return (-7);
		if (C->f_color_r < 0 || C->f_color_g < 0 || C->f_color_b < 0
			|| C->f_color_r > 255 || C->f_color_g > 255
			|| C->f_color_b > 255)
			return (-7);
		return (1);
	}
	return (0);
}

int		sj_parse_f2(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i + 1] != ' ')
		return (-1);
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	C->f_color_r = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == ','))
		i++;
	C->f_color_g = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == ','))
		i++;
	C->f_color_b = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i])
		if (line[i++] != ' ')
			return (1);
	return (0);
}

int		sj_parse_c(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'C')
	{
		if (C->up_c)
			return (-10);
		C->up_c = 1;
		if (sj_parse_c2(line, cub))
			return (-7);
		if (C->c_color_r < 0 || C->c_color_g < 0 || C->c_color_b < 0
			|| C->c_color_r > 255 || C->c_color_g > 255
			|| C->c_color_b > 255)
			return (-7);
		return (1);
	}
	return (0);
}

int		sj_parse_c2(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i + 1] != ' ')
		return (-1);
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	C->c_color_r = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == ','))
		i++;
	C->c_color_g = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == ','))
		i++;
	C->c_color_b = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i])
		if (line[i++] != ' ')
			return (1);
	return (0);
}
