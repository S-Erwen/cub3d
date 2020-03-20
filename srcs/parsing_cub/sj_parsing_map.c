/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 07:15:51 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/09 09:04:30 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
**	PAS DU TOUT FINI !!!!
*/

int		sj_parsing_map(t_cub *cub, char *line)
{
	char	*str;

	str = sj_parsing_linemap(line, cub);
	if (!str)
		return (-12);
	if ((str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		&& (str[0] != ' ' || str[ft_strlen(str) - 1] != ' '))
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

char	*sj_parsing_linemap(char *line, t_cub *cub)
{
	char	*str;
	int		count;

	C->in = 0;
	C->yn = 0;
	count = sj_count_map_line(line);
	if (count == -12)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	if (sj_check_spcline(line, C->in))
	{
		str = sj_free(str);
		return (NULL);
	}
	if (!C->kr)
		C->kr = ft_strdup("");
	if (!(str = sj_line_to_str(line, cub, str)))
	{
		str = sj_free(str);
		C->kr = sj_free(C->kr);
		return (NULL);
	}
	C->kr = ft_add_char(C->kr, '\n');
	return (str);
}

int		sj_count_map_line(char *line)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
		{
			if (line[i] && line[i] == ' '
				&& line[i + 1] && line[i + 1] == ' ' && line[i + 2])
			{
				count++;
				i += 2;
			}
			else if (line[i] == ' ')
				i++;
		}
		if (L[i] == '1' || L[i] == '0' || L[i] == '2'
			|| L[i] == 'N' || L[i] == 'W' || L[i] == 'E' || L[i] == 'S')
			count++;
		else if (line[i] != ' ' && line[i])
			return (-12);
		if (line[i])
			i++;
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
	C->line_map = sj_free(C->line_map);
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
