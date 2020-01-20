/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_check_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 01:11:25 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:59:45 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_check_tab(t_cub *cub)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (cub->tab_map[i])
		i++;
	while (cub->tab_map[i - 1][y])
		if (cub->tab_map[i - 1][y++] != '1')
			return (-12);
	if ((ft_strlen(cub->tab_map[0]) * i) != ft_strlen(cub->line_map))
		return (-12);
	if (!ft_strchr(cub->line_map, 'S') && !ft_strchr(cub->line_map, 'W')
		&& !ft_strchr(cub->line_map, 'E') && !ft_strchr(cub->line_map, 'N'))
		return (-12);
	return (0);
}
