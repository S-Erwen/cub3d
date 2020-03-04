/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 07:15:51 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/03 06:43:32 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
**	PAS DU TOUT FINI !!!!
*/

int		sj_parsing_map(t_cub *cub, char *line)
{
	char	*str;

	str = sj_parsing_linemap(line);
	if (!str)
		return (-12);
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
	{
		free(str);
		return (-12);
	}
	str = ft_add_char(str, '\n');
	if (!C->line_map)
	{
		if (ft_strchr(str, '0') || ft_strchr(str, '2'))
			return (-12);
		C->line_map = ft_strdup(str);
		free(str);
	}
	else
		C->line_map = ft_strjoin_with_free(C->line_map, str, 3);
	return (0);
}

char	*sj_parsing_linemap(char *line)
{
	char	*str;
	int		count;
	int		i;
	int		y;

	i = 0;
	y = 0;
	count = sj_count_map_line(line);
	if (count == -12)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	while (line[i])
	{
		while (line[i] == ' ')
		{
			if (line[i] == ' ' && line[i + 1] == ' ')
			{
				str[y++] = '1';
				i += 2;
			}
			else if (line[i] == ' ')
				i++;
		}
		while (line[i] == '1' || line[i] == '0' || line[i] == '2'
			|| line[i] == 'N' || line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'S')
			str[y++] = line[i++];
		if (line[i])
			i++;
	}
	str[y] = '\0';
	return (str);
}

int		sj_count_map_line(char *line)
{
	int		count;
	int		i;

	i = 0;
	count = -1;
	while (line[++i])
	{
		while (line[i] == ' ')
		{
			if (line[i] == ' ' && line[i + 1] == ' ')
			{
				count++;
				i += 2;
			}
			else if (line[i] == ' ')
				i++;
		}
		if (line[i] == '1' || line[i] == '0' || line[i] == '2'
			|| line[i] == 'N' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'S')
			count++;
		else if (line[i] != ' ')
			return (-12);
	}
	return (count);
}

void	sj_clean_line(t_cub *cub)
{
	int		i;
	int		y;
	char	*str;

	i = sj_count_clean(cub);
	y = 0;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return ;
	i = 0;
	while (C->line_map[i])
	{
		if (C->line_map[i] == '\n')
			i++;
		else
			str[y++] = C->line_map[i++];
	}
	str[y] = '\0';
	free(C->line_map);
	C->line_map = ft_strdup(str);
	free(str);
}

int		sj_count_clean(t_cub *cub)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (C->line_map[i])
	{
		if (C->line_map[i] == '\n')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}
