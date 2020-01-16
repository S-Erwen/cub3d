/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_stderr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 05:27:18 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 08:17:19 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		sj_stderr_argcub(int ac, char **gv)
{
	if (ac < 2 || ac > 3)
	{
		ft_printf(RED);
		ft_printf("Error\n__ERROR_ARG__\n");
		return (0);
	}
	if (!ft_strnstr(gv[1], ".cub", ft_strlen(gv[1])))
	{
		ft_printf(RED);
		ft_printf("Error\n__ERROR_CUB_NOFOUND__\n");
		return (0);
	}
	return (1);
}

void	sj_stderr_parcing(int nb)
{
	if (nb == -1)
		t_printf("__ERROR__RESOLUTION__\n");
	if (nb == -2)
		t_printf("__ERROR__TEXTURE_NORD__\n");
	if (nb == -3)
		t_printf("__ERROR__TEXTURE_SOUTH__\n");
	if (nb == -4)
		t_printf("__ERROR__TEXTURE_WEST__\n");
	if (nb == -5)
		t_printf("__ERROR__TEXTURE_EAST__\n");
	if (nb == -6)
		t_printf("__ERROR__SPRITE__\n");
	if (nb == -7)
		t_printf("__ERROR__COLOR_SOL__\n");
	if (nb == -8)
		t_printf("__ERROR__COLOR_PLAFOND__\n");
	if (nb == -9)
		t_printf("__ERROR__READ__\n");
	if (nb == -10)
		t_printf("__ERROR__DUPLICATION__\n");
	if (nb == -11)
		t_printf("__ERROR__INCOMPLET_CUB__\n");
	if (nb == -12)
		t_printf("__ERROR__MAP__\n");
}