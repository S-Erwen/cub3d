/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 09:18:31 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:03:20 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_len(unsigned int n, char *base)
{
	long unsigned int	len;

	len = 1;
	while (n /= ft_strlen(base))
		len++;
	return (len);
}

char					*ft_utoa_base(unsigned int n, char *base)
{
	char				*str;
	unsigned int		i;

	i = ft_len(n, base);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--i] = base[n % ft_strlen(base)];
		n /= ft_strllen(base);
	}
	return (str);
}
