/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_douilled_putstr.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 08:30:31 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 17:48:06 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_douilled_putstr(char *s, int douille)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[i] || douille)
	{
		if (!s[i] && douille)
		{
			douille--;
			write(1, "\0", 1);
			i++;
		}
		else
			size += write(1, &s[i++], 1);
	}
	return (size);
}
