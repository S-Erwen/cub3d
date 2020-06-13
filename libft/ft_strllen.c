/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strllen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 07:31:14 by esidelar          #+#    #+#             */
/*   Updated: 2020/06/13 04:02:53 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

long unsigned int		ft_strllen(const char *s)
{
	long unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
