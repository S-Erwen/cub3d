/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 19:12:30 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 23:19:52 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
