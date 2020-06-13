/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:00:27 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:03:02 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!big)
		return (NULL);
	if (!little || little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i < len)
	{
		y = 0;
		while (big[i] && big[i + y] == little[y] && (i + y) < len)
		{
			y++;
			if (little[y] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
