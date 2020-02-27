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
	else if (ret <= -3)
		free(C->path_no);
	else if (ret <= -4)
		free(C->path_so);
	else if (ret <= -5)
		free(C->path_we);
	else if (ret <= -6)
		free(C->path_ea);
	else if (ret <= -7)
		free(C->path_sprit);
	ult_vii_to_xii(ret, cub);
}

void	ult_vii_to_xii(int ret, t_cub *cub)
{
	int		i;

	i = 0;
	if (ret >= -12 && C->line_map)
	{
		free(C->line_map);
		while (C->tab_map[i])
			i++;
		while (i)
			free(C->tab_map[i--]);
	}
}
