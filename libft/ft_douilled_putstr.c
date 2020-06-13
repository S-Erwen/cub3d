/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_douilled_putstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 08:30:31 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:57 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_douilled_putstr(char *s, int douille)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[i] || douille)
	{
		if (!s[i] && douille)
		{
			douille--;
			write(1, "\0", 1);
			i++;
		}
		else
			size += write(1, &s[i++], 1);
	}
	return (size);
}
