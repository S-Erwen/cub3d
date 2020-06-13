/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:26:42 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:01:33 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dust;
	unsigned char		*mirage;
	size_t				i;

	i = 0;
	dust = (unsigned char *)dest;
	mirage = (unsigned char *)src;
	while (i < n)
	{
		dust[i] = mirage[i];
		if (mirage[i] == ((unsigned char)c))
			return ((void *)(dest + i + 1));
		i++;
	}
	return (NULL);
}
