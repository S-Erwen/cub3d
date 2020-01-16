/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_r.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:10:54 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 07:11:15 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		sj_parse_r(char *line, t_cub *cub)
{
	int			i;
	static int	up;

	i = 0;
	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strchr(line, 'R'))
	{
		while (line[i] && line[i] > '9' && line[i] < '0')
			i++;
		cub->res_x = ft_atoi(line);
		while (line[i] && line[i] <= '9' && line[i] >= '0')
			i++;
		while (line[i] && line[i] > '9' && line[i] < '0')
			i++;
		cub->res_x = ft_atoi(line);
		if (cub->res_x <= 0 || cub->res_y <= 0)
			return (-1);
		up = 1;
		return (1);
	}
	return (0);
}
