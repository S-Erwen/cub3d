/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parsing_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 07:15:51 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 08:22:48 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"


/*
**	PAS DU TOUT FINI !!!!
*/

int		sj_parsing_map(t_cub *cub, char *line)
{
	char	*str;
	int		count;
	int		i;
	int		y;

	i = 0;
	y = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
			count++;
		if (line[i] != '1' || line[i] != '0' || line[i] != '2'
			|| line[i] != ' ')
			return (-12);
		i++;
	}
	i = 0;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		while (line[i] == '1' || line[i] == '0' || line[i] == '2')
		{
			str[y] = line[i];
			i++;
		}
		i++;
	}
	str[y] = '\0';
	return (str);
}
