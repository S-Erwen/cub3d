/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:03:25 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:50 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	long	nb;
	long	count;
	long	i;

	i = 0;
	count = 1;
	nb = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			count = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i++] - 48;
	}
	return (nb * count);
}
