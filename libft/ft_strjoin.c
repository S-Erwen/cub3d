/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 21:59:19 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/01 09:20:24 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			sj_free_s1_or_s2(char *s1, char *s2, int fre)
{
	if (fre == 1)
	{
		free(s1);
		s1 = NULL;
	}
	if (fre == 2)
	{
		free(s2);
		s2 = NULL;
	}
}

char			*ft_strjoin(char *s1, char *s2, int fre)
{
	unsigned int	i;
	unsigned int	y;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	y = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * i + y + 1)))
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	sj_free_s1_or_s2(s1, s2, fre);
	return (str);
}
