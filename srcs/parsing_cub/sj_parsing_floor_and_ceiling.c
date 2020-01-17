/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_floor_and_ceiling.c                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sanjaro <sanjaro@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:13:44 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 02:10:30 by sanjaro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_f(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strchr(line, 'F'))
	{
		sj_parse_f2(line, cub);
		if (cub->f_color_r < 0 || cub->f_color_r < 0 || cub->f_color_b < 0
			|| cub->f_color_r > 255 || cub->f_color_r > 255
			|| cub->f_color_b > 255)
			return (-7);
		up = 1;
		return (1);
	}
	return (0);
}

void	sj_parse_f2(char *line, t_cub *cub)
{
	int		i;

	i = 0;
	while (line[i] && line[i] > '9' && line[i] < '0')
		i++;
	cub->f_color_r = ft_atoi(line);
	while (line[i] && line[i] <= '9' && line[i] >= '0')
		i++;
	while (line[i] && line[i] > '9' && line[i] < '0')
		i++;
	cub->f_color_g = ft_atoi(line);
	while (line[i] && line[i] <= '9' && line[i] >= '0')
		i++;
	while (line[i] && line[i] > '9' && line[i] < '0')
		i++;
	cub->f_color_b = ft_atoi(line);
}

int		sj_parse_s(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strchr(line, 'C'))
	{
		sj_parse_s2(line, cub);
		if (cub->c_color_r < 0 || cub->c_color_r < 0 || cub->c_color_b < 0
			|| cub->c_color_r > 255 || cub->c_color_r > 255
			|| cub->c_color_b > 255)
			return (-7);
		up = 1;
		return (1);
	}
	return (0);
}

void	sj_parse_s2(char *line, t_cub *cub)
{
	int		i;

	i = 0;
	while (line[i] && line[i] > '9' && line[i] < '0')
		i++;
	cub->c_color_r = ft_atoi(line);
	while (line[i] && line[i] <= '9' && line[i] >= '0')
		i++;
	while (line[i] && line[i] > '9' && line[i] < '0')
		i++;
	cub->c_color_g = ft_atoi(line);
	while (line[i] && line[i] <= '9' && line[i] >= '0')
		i++;
	while (line[i] && line[i] > '9' && line[i] < '0')
		i++;
	cub->c_color_b = ft_atoi(line);
}
