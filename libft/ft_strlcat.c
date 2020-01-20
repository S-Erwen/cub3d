/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 18:06:29 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 23:04:36 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sizedest;

	sizedest = 0;
	while (dest[sizedest] && sizedest < size)
		sizedest++;
	if (!size)
		return (ft_strlen(src));
	if (size == sizedest)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] && (sizedest + i) < size - 1)
	{
		dest[sizedest + i] = src[i];
		i++;
	}
	dest[sizedest + i] = '\0';
	return (sizedest + ft_strlen(src));
}
