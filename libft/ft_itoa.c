/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:28:44 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:00:25 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getlen(unsigned int n)
{
	unsigned int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char				*ft_itoa(int n)
{
	char			*res;
	int				i;
	char			sing;
	unsigned int	unb;

	sing = n < 0;
	unb = (sing ? -n : n);
	i = ft_getlen(unb) + sing;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = 0;
	res[0] = '-';
	if (unb == 0)
		res[0] = '0';
	while (unb)
	{
		res[--i] = unb % 10 + '0';
		unb /= 10;
	}
	return (res);
}
