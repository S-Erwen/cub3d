/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_ultimatefree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:42:46 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/03 06:42:47 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ult_i_to_vii(int ret, t_cub *cub)
{
	if (ret == -10)
	{
		if (C->path_ea)
			free(C->path_ea);
		if (C->path_no)
			free(C->path_no);
		if (C->path_so)
			free(C->path_so);
		if (C->path_we)
			free(C->path_we);
		if (C->path_sprit)
			free(C->path_sprit);
	}
	if (ret <= -3 && ret != -13 && ret != -10)
		free(C->path_no);
	if (ret <= -4 && ret != -13 && ret != -10)
		free(C->path_so);
	if (ret <= -5 && ret != -13 && ret != -10)
		free(C->path_we);
	if (ret <= -6 && ret != -13 && ret != -10)
		free(C->path_ea);
	if (ret <= -7 && ret != -13 && ret != -10)
		free(C->path_sprit);
	ult_vii_to_xii(ret, cub);
}

void	ult_vii_to_xii(int ret, t_cub *cub)
{
	int		i;

	i = 0;
	if (ret <= -12 && C->line_map && ret != -13)
	{
		free(C->line_map);
		while (C->tab_map[i])
			i++;
		while (i)
			free(C->tab_map[i--]);
	}
	free(C->K);
	free(C->SP);
	free(C->CS);
	free(C);
}
