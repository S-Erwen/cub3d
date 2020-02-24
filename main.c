/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 04:51:03 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 04:54:08 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./include/cub3d.h"

int		main(int ac, char **gv)
{
	int		ret;

	ret = sj_cub(ac, gv);
	return (ret);
}
