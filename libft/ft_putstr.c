/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 01:18:45 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:02:20 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putstr(char *s)
{
	size_t	size;

	size = 0;
	if (s)
		size = write(1, s, ft_strlen(s));
	return (size);
}
