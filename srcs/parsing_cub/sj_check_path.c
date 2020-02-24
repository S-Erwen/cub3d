/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_check_path.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 10:25:13 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 02:55:31 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_check_path(t_cub *cub)
{
	int		fd;

	if ((fd = open(C->path_ea, 0x0000) < 0)
		|| (fd = open(C->path_so, 0x0000) < 0)
		|| (fd = open(C->path_we, 0x0000) < 0)
		|| (fd = open(C->path_no, 0x0000) < 0)
		|| (fd = open(C->path_sprit, 0x0000) < 0))
		return (-13);
	close(fd);
	if (!ft_strnstr(C->path_ea, ".xpm", ft_strlen(C->path_ea))
		|| !ft_strnstr(C->path_so, ".xpm", ft_strlen(C->path_so))
		|| !ft_strnstr(C->path_we, ".xpm", ft_strlen(C->path_we))
		|| !ft_strnstr(C->path_no, ".xpm", ft_strlen(C->path_no))
		|| !ft_strnstr(C->path_sprit, ".xpm", ft_strlen(C->path_sprit)))
		return (-14);
	return (0);
}
