/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:10:54 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:52 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_r(char *line, t_cub *cub)
{
	int			i;

	i = 0;
	if (line[0] == 'R')
	{
		if (C->res_x || C->res_y)
			return (-10);
		while (line[i] && (line[i] > '9' || line[i] < '0'))
			i++;
		C->res_x = ft_atoi(line + i);
		while (line[i] && line[i] <= '9' && line[i] >= '0')
			i++;
		while (line[i] && (line[i] > '9' || line[i] < '0'))
			i++;
		C->res_y = ft_atoi(line + i);
		if (C->res_x <= 0 || C->res_y <= 0)
			return (-1);
		return (1);
	}
	return (0);
}
