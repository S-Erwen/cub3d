/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:12:30 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:02:56 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*src;
	unsigned int	t;

	if (!s)
		return (NULL);
	t = 0;
	while (s[t])
		t++;
	if (!(src = (char *)malloc(sizeof(char) * t + 1)))
		return (NULL);
	src[t] = 0;
	t = 0;
	while (s[t])
	{
		src[t] = (*f)(t, s[t]);
		t++;
	}
	return (src);
}
