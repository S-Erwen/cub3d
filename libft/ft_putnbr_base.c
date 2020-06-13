/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 05:00:21 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:02:05 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base(unsigned long long int n, char *base)
{
	char	c;

	c = 0;
	if (n >= ft_strlen(base))
	{
		ft_putnbr_base(n / ft_strlen(base), base);
		c = base[n % ft_strlen(base)];
	}
	ft_putchar(c);
}
