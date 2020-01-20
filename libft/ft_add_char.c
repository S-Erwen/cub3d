/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_char.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/08 04:59:23 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 04:06:06 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_char(char *s1, char const s2)
{
	unsigned int	i;
	char			*str;

	i = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s2;
	str[++i] = '\0';
	free(s1);
	return (str);
}
