/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 01:18:45 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 03:44:46 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
