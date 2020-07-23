/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_stderr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 05:27:18 by esidelar          #+#    #+#             */
/*   Updated: 2020/07/23 14:32:57 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
**	SI IL Y A PAS 2 ARGS OU 1 BAH PAS POSSIBLE DE PARSER
*/

int		sj_argcub(int ac, char **gv)
{
	if (ac < 2 || ac > 3)
	{
		ft_printf(RED);
		ft_printf("Error\n__ERROR_ARG__\n");
		return (0);
	}
	if (ac == 2)
		if (!ft_strnstr(gv[1], ".cub", ft_strlen(gv[1])))
		{
			ft_printf(RED);
			ft_printf("Error\n__ERROR_CUB_NOFOUND__\n");
			return (0);
		}
	if (ac == 3)
		if (!ft_strnstr(gv[2], ".cub", ft_strlen(gv[2]))
			&& !ft_strnstr(gv[1], ".cub", ft_strlen(gv[1])))
		{
			ft_printf(RED);
			ft_printf("Error\n__ERROR_CUB_NOFOUND__\n");
			return (0);
		}
	return (1);
}

int		sj_stderr_argcub(int ac, char **gv, t_cub *cub)
{
	int		ret;

	if ((ret = sj_argcub(ac, gv)) == 0)
		return (0);
	if (ac == 3)
	{
		if (ft_strnstr(gv[2], "--save", ft_strlen(gv[2]))
			|| ft_strnstr(gv[1], "--save", ft_strlen(gv[1])))
			C->help++;
		else
		{
			ft_printf("\033[0;31mError\n__ERROR_BAD_ARG__\n");
			return (0);
		}
	}
	if (ft_strnstr(gv[1], ".cub", ft_strlen(gv[1])))
		C->arg = 1;
	else
		C->arg = 2;
	return (1);
}

void	sj_stderr_parsing(int nb)
{
	if (nb == -1)
		ft_printf("__ERROR__RESOLUTION__\n");
	if (nb == -2)
		ft_printf("__ERROR__TEXTURE_NORD__\n");
	if (nb == -3)
		ft_printf("__ERROR__TEXTURE_SOUTH__\n");
	if (nb == -4)
		ft_printf("__ERROR__TEXTURE_WEST__\n");
	if (nb == -5)
		ft_printf("__ERROR__TEXTURE_EAST__\n");
	if (nb == -6)
		ft_printf("__ERROR__SPRITE__\n");
	if (nb == -7)
		ft_printf("__ERROR__COLOR_SOL__\n");
	if (nb == -8)
		ft_printf("__ERROR__COLOR_PLAFOND__\n");
	if (nb == -9)
		ft_printf("__ERROR__READ__\n");
	if (nb == -10)
		ft_printf("__ERROR__DUPLICATION__\n");
	if (nb == -11)
		ft_printf("__ERROR__INCOMPLET_CUB__\n");
	if (nb == -12)
		ft_printf("__ERROR__MAP__\n");
	sj_stderr_parsing_tho(nb);
}

void	sj_stderr_parsing_tho(int nb)
{
	if (nb == -13)
		ft_printf("__ERROR_FILE__\n");
	if (nb == -14)
		ft_printf("__ERROR_NO_XPM_FILE__\n");
	if (nb == -15)
		ft_printf("__ERROR_BAD_XPM_FILE__\n");
	if (nb == -16)
		ft_printf("__ERROR_MALLOC__\n");
}

char	*sj_free(char *str)
{
	free(str);
	str = NULL;
	return (str);
}
