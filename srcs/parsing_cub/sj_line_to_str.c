/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_line_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:08:20 by esidelar          #+#    #+#             */
/*   Updated: 2020/07/22 16:59:47 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char		*sj_line_to_str(char *line, t_cub *cub, char *str)
{
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

int			sj_check_spcline(char *line, int i)
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

void		sj_add_for_kr(t_cub *cub, size_t len)
{
	int	i;

	i = 0;
	while (C->kr_tab[i])
	{
		while (ft_strlen(C->kr_tab[i]) < len)
			C->kr_tab[i] = ft_add_char(C->kr_tab[i], ' ');
		i++;
	}
}

int			sj_suit_parse(t_cub *cub)
{
	int i;

	i = 0;
	if (!C->line_map)
		return (-12);
	C->tab_map = ft_split(C->line_map, '\n');
	if (sj_fck_new_sujet(cub))
	{
		while (C->kr_tab[i])
			i++;
		while (i)
		{
			C->kr_tab[i] = sj_free(C->kr_tab[i]);
			i--;
		}
		C->kr_tab[i] = sj_free(C->kr_tab[i]);
		free(C->kr_tab);
		C->kr_tab = NULL;
		return (-12);
	}
	C->kr_tab = NULL;
	sj_newline(cub);
	sj_clean_line(cub);
	return (0);
}
