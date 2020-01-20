/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_path.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:11:42 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 06:18:14 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		sj_parse_no(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		if (cub->path_no)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-2);
			else
			{
				cub->path_no = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			cub->path_no = ft_strdup(ft_strchr(line, '.'));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_so(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		if (cub->path_so)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-3);
			else
			{
				cub->path_so = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			cub->path_so = ft_strdup(ft_strchr(line, '.'));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_we(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		if (cub->path_we)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-4);
			else
			{
				cub->path_we = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			cub->path_we = ft_strdup(ft_strchr(line, '.'));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_ea(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		if (cub->path_ea)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-5);
			else
			{
				cub->path_ea = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			cub->path_ea = ft_strdup(ft_strchr(line, '.'));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_sprit(char *line, t_cub *cub)
{
	int		i;

	i = sj_space_skip(line);
	if (line[i] == 'S')
	{
		if (cub->path_sprit)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-6);
			else
			{
				cub->path_sprit = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			cub->path_sprit = ft_strdup(ft_strchr(line, '.'));
			return (1);
		}
	}
	return (0);
}
