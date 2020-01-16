/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:09:34 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 06:45:07 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int     sj_cub(int ac, char **gv)
{
    t_cub   cub;
    int     ret;

    if (!sj_stderr_argcub(ac, gv))
        exit(EXIT_FAILURE);
    if ((ret = sj_parsing(cub, gv)) > 0)
    {
        ft_printf(RED);
		ft_printf("Error\n");
        sj_stderr_parcing(ret);
        exit(EXIT_FAILURE);
    }
}
