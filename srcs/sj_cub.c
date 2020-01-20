/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:09:34 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 04:53:35 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		sj_cub(int ac, char **gv)
{
	t_cub	cub;
	t_mlx	mlx;
	int		ret;
	int		i = 0; // for print map

	sj_cub_init(&cub);
	if (!sj_stderr_argcub(ac, gv, &cub))
		exit(EXIT_FAILURE);
	if ((ret = sj_parse_all(&cub, gv)) < 0)
	{
		ft_printf(RED);
		ft_printf("Error\n");
		sj_stderr_parsing(ret);
		exit(EXIT_FAILURE);
	}
	dprintf(1, "LINE = {\n%s}\n", cub.line_map);
	while (cub.tab_map[i])
		dprintf(1, "TAB = {%s}\n", cub.tab_map[i++]);
	sj_cub_free(&cub);
	sj_creat_new_windows(&mlx, &cub);
	exit(EXIT_SUCCESS);
	// Faire la suite
}

void	sj_cub_init(t_cub *cub)
{
	cub->res_x = 0;
	cub->res_y = 0;
	cub->path_no = NULL;
	cub->path_so = NULL;
	cub->path_we = NULL;
	cub->path_ea = NULL;
	cub->path_sprit = NULL;
	cub->f_color_r = 0;
	cub->f_color_g = 0;
	cub->f_color_b = 0;
	cub->c_color_r = 0;
	cub->c_color_g = 0;
	cub->c_color_b = 0;
	cub->help = 0;
	cub->line_map = NULL;
	cub->tab_map = NULL;
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
