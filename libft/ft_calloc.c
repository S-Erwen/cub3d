/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:19:02 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 03:59:55 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t nmemb, size_t size)
{
	void		*dest;

	if (!(dest = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(dest, size * nmemb);
	return (dest);
}
