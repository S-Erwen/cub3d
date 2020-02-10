/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_floor_and_ceiling.c                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:13:44 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:52 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_f(char *line, t_cub *cub)
{
	if (line[0] == 'F')
	{
		sj_parse_f2(line, cub);
		if (C->f_color_r < 0 || C->f_color_r < 0 || C->f_color_b < 0
			|| C->f_color_r > 255 || C->f_color_r > 255
			|| C->f_color_b > 255)
			return (-7);
		return (1);
	}
	return (0);
}

void	sj_parse_f2(char *line, t_cub *cub)
{
	int		i;

	i = 0;
	while (line[i] && (line[i] > '9' || line[i] < '0'))
		i++;
	C->f_color_r = ft_atoi(line + i);
	while (line[i] && (line[i] <= '9' && line[i] >= '0'))
		i++;
	while (line[i] && (line[i] > '9' || line[i] < '0'))
		i++;
	C->f_color_g = ft_atoi(line + i);
	while (line[i] && (line[i] <= '9' && line[i] >= '0'))
		i++;
	while (line[i] && (line[i] > '9' || line[i] < '0'))
		i++;
	C->f_color_b = ft_atoi(line + i);
}

int		sj_parse_c(char *line, t_cub *cub)
{
	if (line[0] == 'C')
	{
		sj_parse_c2(line, cub);
		if (C->c_color_r < 0 || C->c_color_r < 0 || C->c_color_b < 0
			|| C->c_color_r > 255 || C->c_color_r > 255
			|| C->c_color_b > 255)
			return (-7);
		return (1);
	}
	return (0);
}

void	sj_parse_c2(char *line, t_cub *cub)
{
	int		i;

	i = 0;
	while (line[i] && (line[i] > '9' || line[i] < '0'))
		i++;
	C->c_color_r = ft_atoi(line + i);
	while (line[i] && (line[i] <= '9' && line[i] >= '0'))
		i++;
	while (line[i] && (line[i] > '9' || line[i] < '0'))
		i++;
	C->c_color_g = ft_atoi(line + i);
	while (line[i] && (line[i] <= '9' && line[i] >= '0'))
		i++;
	while (line[i] && (line[i] > '9' || line[i] < '0'))
		i++;
	C->c_color_b = ft_atoi(line + i);
}
