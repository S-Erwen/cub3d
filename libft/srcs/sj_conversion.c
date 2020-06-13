/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 00:01:32 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:58:46 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_ptr(t_print *t)
{
	char	*str;

	str = ft_lltoa_base((intptr_t)va_arg(t->list, void *), "0123456789abcdef");
	if (t->flags[0] == 'p' && sj_not_found_number(str) && t->point)
	{
		free(str);
		str = NULL;
	}
	str = sj_free_join("0x", str, 2);
	t->x_write.str = ft_strdup(str);
	free(str);
}

void	sj_csp(const char *s, t_print *t)
{
	char	*str;
	char	c;

	if (s[t->i] == 'c')
	{
		c = (char)va_arg(t->list, int);
		t->x_write.str = sj_free_add(t->x_write.str, c);
	}
	else if (s[t->i] == 's')
	{
		str = va_arg(t->list, char *);
		if (str)
			t->x_write.str = ft_strdup(str);
		else
			t->x_write.str = ft_strdup("(null)");
	}
	else if (s[t->i] == 'p')
		sj_ptr(t);
}

void	sj_dui(const char *s, t_print *t)
{
	int	nb;

	nb = 0;
	if (s[t->i] == 'd')
	{
		nb = va_arg(t->list, long long int);
		t->x_write.str = ft_ltoa(nb);
	}
	else if (s[t->i] == 'i')
	{
		nb = va_arg(t->list, long long int);
		t->x_write.str = ft_ltoa(nb);
	}
	else if (s[t->i] == 'u')
	{
		nb = va_arg(t->list, unsigned int);
		t->x_write.str = ft_utoa_base(nb, "0123456789");
	}
}

void	sj_x(const char *s, t_print *t)
{
	int		nb;

	if (s[t->i] == 'x')
	{
		nb = va_arg(t->list, unsigned int);
		t->x_write.str = ft_utoa_base(nb, "0123456789abcdef");
	}
	else if (s[t->i] == 'X')
	{
		nb = va_arg(t->list, unsigned int);
		t->x_write.str = ft_utoa_base(nb, "0123456789ABCDEF");
	}
}
