/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:41:41 by esidelar          #+#    #+#             */
/*   Updated: 2020/07/29 06:44:45 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned long long		ft_atol(const char *nptr)
{
	unsigned long long	nb;
	unsigned long long	count;
	unsigned long long	i;

	i = 0;
	count = 1;
	nb = 0;
	if (!nptr || !nptr[0] || nptr[0] == ',')
		return (-256);
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
