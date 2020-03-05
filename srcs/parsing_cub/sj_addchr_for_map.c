#include "../../include/cub3d.h"

void	sj_newline(t_cub *cub)
{
	int		i;

	i = 0;
	free(C->line_map);
	C->line_map = ft_strdup(C->tab_map[i++]);
	C->line_map = ft_add_char(C->line_map, '\n');
	while (C->tab_map[i])
	{
		C->line_map = ft_strjoin_with_free(C->line_map, C->tab_map[i++], 1);
		C->line_map = ft_add_char(C->line_map, '\n');
	}
}

int		sj_fck_new_sujet(t_cub *cub)
{
	size_t	len;
	int		i;
	int		ret;

	i = 0;
	len = sj_count_new_sujet(cub);
	while (C->tab_map[i])
	{
		if (C->tab_map[i + 1])
		{
			if (ft_strlen(C->tab_map[i]) != len)
			{
				if (ft_strlen(C->tab_map[i]) > ft_strlen(C->tab_map[i + 1]))
					ret = sj_cmp_ud(cub, &i, len, 0);
				else
					ret = sj_cmp_ud(cub, &i, len, 1);
				if (ret == -12)
					return (ret);
			}
		}
		else if (ft_strlen(C->tab_map[i]) != len)
			ret = sj_cmp_end(cub, &i, len);
		i++;
	}
	return (0);
}

int		sj_cmp_end(t_cub *cub, int *i, size_t len)
{
	while (ft_strlen(C->tab_map[*i]) < len)
		C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
	return (0);
}

int		sj_cmp_ud(t_cub *cub, int *i, size_t len, int bool)
{
	int	y;

	if (bool)
	{
		while (ft_strlen(C->tab_map[*i]) < ft_strlen(C->tab_map[*i + 1]))
		{
			if (C->tab_map[*i + 1][ft_strlen(C->tab_map[*i])] == '0')
				return (-12);
			C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
		}
		while (ft_strlen(C->tab_map[*i]) < len)
			C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
		return (0);
	}
	y = ft_strlen(C->tab_map[*i + 1]);
	while (C->tab_map[*i][y])
	{
		if (C->tab_map[*i][y] == '0')
			return (-12);
		y++;
	}
	while (ft_strlen(C->tab_map[*i]) < len)
		C->tab_map[*i] = ft_add_char(C->tab_map[*i], '1');
	return (0);
}

size_t	sj_count_new_sujet(t_cub *cub)
{
	size_t	max;
	int		i;

	i = 0;
	max = 0;
	while (C->tab_map[i])
	{
		if (ft_strlen(C->tab_map[i]) > max)
			max = ft_strlen(C->tab_map[i++]);
		else
			i++;
	}
	return (max);
}
