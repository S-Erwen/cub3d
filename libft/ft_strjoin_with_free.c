/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_with_free.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sanjaro <sanjaro@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/17 01:02:29 by sanjaro      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 01:02:54 by sanjaro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	sj_free_s1_or_s2(char *s1, char *s2, int fre)
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

char	*ft_strjoin_with_free(char *s1, char *s2, int fre)
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
