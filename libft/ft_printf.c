/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 01:32:23 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:27:25 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	sj_initialise_pt2(t_print *t)
{
	t->minus = 0;
	t->zero = 0;
	t->point = 0;
	t->star = 0;
	t->star_two = 0;
	t->x_parce.nb = 0;
	t->x_parce.i = 0;
	t->x_parce.temp = 0;
}

void	sj_initialise(t_print *t)
{
	if (t->x_parce.reset == 1)
		free(t->x_parce.gest);
	if (t->flags)
		free(t->flags);
	if (t->precision)
		free(t->precision);
	if (t->pf)
		free(t->pf);
	if (t->gestion)
		free(t->gestion);
	if (t->x_write.str)
		free(t->x_write.str);
	t->flags = NULL;
	t->precision = NULL;
	t->pf = NULL;
	t->gestion = NULL;
	t->x_write.str = NULL;
	t->x_parce.reset = 0;
	sj_initialise_pt2(t);
}

void	sj_set(t_print *t)
{
	t->flags = NULL;
	t->precision = NULL;
	t->pf = NULL;
	t->gestion = NULL;
	t->x_write.str = NULL;
	t->x_parce.reset = 0;
}

void	sj_initialize_in_printf(t_print *t)
{
	t->back_slash = 0;
	t->cheat = 0;
	t->i = 0;
	t->x_write.finish = NULL;
}

int		ft_printf(const char *s, ...)
{
	t_print	t;
	int		i;

	sj_set(&t);
	sj_initialise(&t);
	sj_initialize_in_printf(&t);
	if (!sj_parsing_percent(s))
		return (ft_putstr((char *)s));
	va_start(t.list, s);
	while (s[t.i])
	{
		while (s[t.i] == '%' && s[t.i + 1] == '%' && s[t.i])
			sj_main_printf(&t, 1, s);
		if (s[t.i] == '%' && s[t.i + 1])
			sj_main_printf(&t, 0, s);
		if (s[t.i] != '%' && s[t.i])
			t.x_write.finish = sj_free_add(t.x_write.finish, s[t.i++]);
		sj_initialise(&t);
	}
	va_end(t.list);
	i = ft_putstr(t.x_write.finish) + t.cheat;
	free(t.x_write.finish);
	return (i);
}
