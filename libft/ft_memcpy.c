/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:14:28 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:01:42 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dust;
	unsigned char		*mirage;
	size_t				i;

	if ((dest == src || !n) && (!dest && !src))
		return (NULL);
	i = 0;
	dust = (unsigned char *)dest;
	mirage = (unsigned char *)src;
	while (n > i)
	{
		dust[i] = mirage[i];
		i++;
	}
	return (dest);
}
