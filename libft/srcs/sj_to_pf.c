/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_to_pf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/29 09:43:58 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:38:17 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_to_pf(const char *s, t_print *t)
{
	while (s[t->i] != 'c' && s[t->i] != 's' && s[t->i] != 'p'
		&& s[t->i] != 'd' && s[t->i] != 'u' && s[t->i] != 'i'
		&& s[t->i] != 'x' && s[t->i] != 'X' && s[t->i] != '%')
	{
		if (s[t->i] == '.')
			t->point++;
		if (s[t->i] == '0' && (!t->pf || (t->pf && !t->pf[0])))
			t->zero++;
		if (s[t->i] == '-')
			t->minus++;
		if (s[t->i] == '*')
			sj_stars(t);
		else
			t->pf = sj_free_add(t->pf, s[t->i++]);
	}
	sj_flags(s, t);
}

void	sj_stars(t_print *t)
{
	char	*ito;
	char	*ito_two;

	if (!t->star)
	{
		t->star = va_arg(t->list, int);
		ito = ft_itoa(t->star);
		t->pf = sj_free_join(t->pf, ito, 0);
		free(ito);
	}
	else
	{
		t->star_two = va_arg(t->list, int);
		ito_two = ft_itoa(t->star_two);
		t->pf = sj_free_join(t->pf, ito_two, 0);
		free(ito_two);
	}
	if (t->star < 0 || t->star_two < 0)
		t->minus++;
	t->i++;
}
