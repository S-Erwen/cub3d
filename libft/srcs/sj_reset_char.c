/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_reset_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:11:52 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:33 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		sj_reset_chr(t_print *t)
{
	t->cheat += ft_putstr(t->x_write.finish);
	t->cheat += write(1, "\0", 1);
	free(t->x_write.finish);
	t->x_write.finish = NULL;
}
