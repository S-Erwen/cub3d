/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:48:00 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:01:48 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_neg_atoi(const char *nptr)
{
	long	nb;
	long	count;
	long	i;

	i = 0;
	count = 1;
	nb = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			count = -1;
		while (nptr[i] == '-')
			i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i++] - 48;
	}
	return (nb * count);
}
