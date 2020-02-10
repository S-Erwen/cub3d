/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_path.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:11:42 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 14:47:52 by esidelar    ###    #+. /#+    ###.fr     */
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
		if (C->path_no)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-2);
			else
			{
				C->path_no = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			C->path_no = ft_strdup(ft_strchr(line, '.'));
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
		if (C->path_so)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-3);
			else
			{
				C->path_so = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			C->path_so = ft_strdup(ft_strchr(line, '.'));
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
		if (C->path_we)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-4);
			else
			{
				C->path_we = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			C->path_we = ft_strdup(ft_strchr(line, '.'));
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
		if (C->path_ea)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-5);
			else
			{
				C->path_ea = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			C->path_ea = ft_strdup(ft_strchr(line, '.'));
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
		if (C->path_sprit)
			return (-10);
		if (!ft_strchr(line, '.'))
		{
			if (!ft_strchr(line, '/'))
				return (-6);
			else
			{
				C->path_sprit = ft_strdup(ft_strchr(line, '/'));
				return (1);
			}
		}
		else
		{
			C->path_sprit = ft_strdup(ft_strchr(line, '.'));
			return (1);
		}
	}
	return (0);
}
