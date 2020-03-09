/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_line_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:08:20 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/09 08:34:18 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*sj_line_to_str(char *line, t_cub *cub, char *str)
{
	if (sj_check_spcline(line, C->in))
		return (NULL);
	C->kr = ft_strdup("");
	while (line[C->in])
	{
		if (!(C->in % 2))
		{
			if (line[C->in] != ' ')
			{
				C->kr = ft_add_char(C->kr, line[C->in]);
				str[C->yn++] = line[C->in++];
			}
			else
			{
				C->in++;
				C->kr = ft_add_char(C->kr, ' ');
				str[C->yn++] = '1';
			}
		}
		else if ((line[C->in] != ' ' && line[C->in])
			|| (line[C->in] == ' ' && !line[C->in + 1]))
			return (NULL);
		else
			C->in++;
	}
	str[C->yn++] = '\0';
	return (str);
}

int		sj_check_spcline(char *line, int i)
{
	while (line[i])
	{
		if (i > 1 && line[i] == '0' && line[i - 2] == ' ')
			return (-12);
		if (line[i + 1])
			if (line[i + 2])
				if (i > 1 && line[i] == '0' && line[i + 2] == ' ')
					return (-12);
		i++;
	}
	return (0);
}
