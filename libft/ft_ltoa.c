/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:28:44 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:01:30 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_len(long long int n)
{
	long long int	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char					*ft_ltoa(long long int n)
{
	char			*str;
	long long int	i;
	char			neg;
	long long int	nb;

	neg = n < 0;
	nb = (neg ? -n : n);
	i = ft_len(nb) + neg;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--i] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
