/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:09:34 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/09 04:56:50 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		sj_cub(int ac, char **gv)
{
	t_cub	*cub;
	int		ret;

	if (!(cub = malloc(sizeof(t_cub))))
		return (0);
	if (!(cub->key = malloc(sizeof(t_key))))
		return (0);
	if (!(cub->cast = malloc(sizeof(t_recast))))
		return (0);
	sj_cub_init(cub);
	if (!sj_stderr_argcub(ac, gv, cub))
		exit(EXIT_FAILURE);
	if ((ret = sj_parse_all(cub, gv)) < 0)
	{
		ft_printf(RED);
		ft_printf("Error\n");
		sj_stderr_parsing(ret);
		exit(EXIT_FAILURE);
	}
	sj_init_player(cub);
	sj_creat_new_windows(cub);
	sj_cub_free(cub);
	exit(EXIT_SUCCESS);
}

void	sj_init_player(t_cub *cub)
{
	cub->dbl_pos_x = (int)ft_strchr(cub->line_map, cub->pos) -
		(int)cub->line_map;
	cub->dbl_pos_y = cub->dbl_pos_x;
	cub->dbl_pos_x = (int)cub->dbl_pos_x % ft_strlen(cub->tab_map[0]) + 0.5;
	cub->dbl_pos_y = (int)cub->dbl_pos_y / ft_strlen(cub->tab_map[0]) + 0.5;
	cub->init_pos_x = ft_strchr(cub->line_map, cub->pos) - cub->line_map;
	cub->init_pos_y = cub->init_pos_x;
	cub->init_pos_x = cub->init_pos_x % ft_strlen(cub->tab_map[0]);
	cub->init_pos_y = cub->init_pos_y / ft_strlen(cub->tab_map[0]);
}

void	sj_cub_free(t_cub *cub)
{
	int		i;

	i = 0;
	while (cub->tab_map[i])
		i++;
	while (i)
		free(cub->tab_map[--i]);
	free(cub->line_map);
	free(cub->tab_map);
}
