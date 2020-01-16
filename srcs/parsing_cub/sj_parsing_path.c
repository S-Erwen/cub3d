/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_path.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:11:42 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 07:37:22 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		sj_parse_no(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strnstr(line, "NO", ft_strlen(line)))
	{
		if (!ft_strchr(line, "."))
		{
			if (!ft_strchr(line, "/"))
				return (-2);
			else
			{
				cub->path_no = ft_strdup(ft_strchr(line, "/"));
				return (1);
			}
		}
		else
		{
			cub->path_no = ft_strdup(ft_strchr(line, "."));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_so(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strnstr(line, "SO", ft_strlen(line)))
	{
		if (!ft_strchr(line, "."))
		{
			if (!ft_strchr(line, "/"))
				return (-3);
			else
			{
				cub->path_so = ft_strdup(ft_strchr(line, "/"));
				return (1);
			}
		}
		else
		{
			cub->path_so = ft_strdup(ft_strchr(line, "."));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_we(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strnstr(line, "WE", ft_strlen(line)))
	{
		if (!ft_strchr(line, "."))
		{
			if (!ft_strchr(line, "/"))
				return (-4);
			else
			{
				cub->path_we = ft_strdup(ft_strchr(line, "/"));
				return (1);
			}
		}
		else
		{
			cub->path_we = ft_strdup(ft_strchr(line, "."));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_ea(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strnstr(line, "EA", ft_strlen(line)))
	{
		if (!ft_strchr(line, "."))
		{
			if (!ft_strchr(line, "/"))
				return (-5);
			else
			{
				cub->path_ea = ft_strdup(ft_strchr(line, "/"));
				return (1);
			}
		}
		else
		{
			cub->path_ea = ft_strdup(ft_strchr(line, "."));
			return (1);
		}
	}
	return (0);
}

int		sj_parse_sprit(char *line, t_cub *cub)
{
	static int	up;

	if (up == 1)
		return (-10);
	up = 0;
	if (ft_strnstr(line, "S", ft_strlen(line)))
	{
		if (!ft_strchr(line, "."))
		{
			if (!ft_strchr(line, "/"))
				return (-6);
			else
			{
				cub->path_sprit = ft_strdup(ft_strchr(line, "/"));
				return (1);
			}
		}
		else
		{
			cub->path_sprit = ft_strdup(ft_strchr(line, "."));
			return (1);
		}
	}
	return (0);
}
