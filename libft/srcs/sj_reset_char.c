/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_reset_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 18:11:52 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:38:17 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void		sj_reset_chr(t_print *t)
{
	t->cheat += ft_putstr(t->x_write.finish);
	t->cheat += write(1, "\0", 1);
	free(t->x_write.finish);
	t->x_write.finish = NULL;
}
