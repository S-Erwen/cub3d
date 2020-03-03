/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parsing_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 07:11:42 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/03 06:44:00 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_no(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i++] == 'N' && line[i++] == 'O')
	{
		if (C->path_no)
			return (-10);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '.')
			C->path_no = ft_strdup(ft_strchr(line, '.'));
		else
			return (-2);
		return (1);
	}
	return (0);
}

int		sj_parse_so(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i++] == 'S' && line[i++] == 'O')
	{
		if (C->path_so)
			return (-10);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '.')
			C->path_so = ft_strdup(ft_strchr(line, '.'));
		else
			return (-3);
		return (1);
	}
	return (0);
}

int		sj_parse_we(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i++] == 'W' && line[i++] == 'E')
	{
		if (C->path_we)
			return (-10);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '.')
			C->path_we = ft_strdup(ft_strchr(line, '.'));
		else
			return (-4);
		return (1);
	}
	return (0);
}

int		sj_parse_ea(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i++] == 'E' && line[i++] == 'A')
	{
		if (C->path_ea)
			return (-10);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '.')
			C->path_ea = ft_strdup(ft_strchr(line, '.'));
		else
			return (-5);
		return (1);
	}
	return (0);
}

int		sj_parse_sprit(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i++] == 'S')
	{
		if (C->path_sprit)
			return (-10);
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '.')
			C->path_sprit = ft_strdup(ft_strchr(line, '.'));
		else
			return (-6);
		return (1);
	}
	return (0);
}
