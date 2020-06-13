/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sj_parce_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:15:20 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:01 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	sj_flags(const char *s, t_print *t)
{
	if (s[t->i] == 'c' || s[t->i] == 's' || s[t->i] == 'p'
		|| s[t->i] == 'd' || s[t->i] == 'u' || s[t->i] == 'i'
		|| s[t->i] == 'x' || s[t->i] == 'X' || s[t->i] == '%')
		t->flags = sj_free_add(t->flags, s[t->i]);
}

void	sj_to_str(const char *s, t_print *t)
{
	if (s[t->i] == 'c' || s[t->i] == 's' || s[t->i] == 'p')
		sj_csp(s, t);
	if (s[t->i] == 'd' || s[t->i] == 'u' || s[t->i] == 'i')
		sj_dui(s, t);
	if (s[t->i] == 'x' || s[t->i] == 'X')
		sj_x(s, t);
	if (s[t->i] == '%')
		t->x_write.str = sj_free_add(t->x_write.str, '%');
	t->i++;
}

char	*sj_add_chr(char *s1, char const s2, int bck_slsh)
{
	unsigned int	i;
	char			*str;
	int				douille;

	douille = 0;
	i = 0;
	while (s1[i] || douille < bck_slsh)
	{
		if (!s1[i])
			douille++;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1 + 1)))
		return (NULL);
	str = sj_add_chr_b(s1, bck_slsh, str);
	i = ft_strilen(str);
	str[++i] = s2;
	str[++i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

char	*sj_add_chr_b(char *s1, int bck_slsh, char *str)
{
	int		douille;
	int		i;

	i = 0;
	douille = 0;
	while (s1[i] || douille < bck_slsh)
	{
		if (!s1[i])
			douille++;
		str[i] = s1[i];
		i++;
	}
	return (str);
}

void	sj_parsing(const char *s, t_print *t)
{
	sj_to_pf(s, t);
	sj_to_str(s, t);
	if (t->pf && ft_strlen(t->pf))
		sj_prec_and_flags(t);
	else if ((t->x_write.str && ft_strilen(t->x_write.str)))
		t->x_write.finish = sj_free_join(t->x_write.finish, t->x_write.str, 0);
	else if (t->flags[0] == 'c' && t->x_write.str[0] == 0)
		sj_reset_chr(t);
}
