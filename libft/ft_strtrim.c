/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 22:08:22 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 20:22:44 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	check_c(const char *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	last_lened(int last, const char *s1, const char *set, int first)
{
	while (s1[last])
		last++;
	last--;
	while (check_c(set, s1[first]))
		first++;
	while (check_c(set, s1[last]))
		last--;
	return (last);
}

int			first_lened(int last, const char *s1, const char *set, int first)
{
	while (s1[last])
		last++;
	last--;
	while (check_c(set, s1[first]))
		first++;
	while (check_c(set, s1[last]))
		last--;
	return (first);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		first;
	size_t		last;
	size_t		i;
	char		*str;

	first = 0;
	last = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	last = last_lened(last, s1, set, first);
	first = first_lened(last, s1, set, first);
	if (first == ft_strlen(s1))
	{
		if (!(str = (char *)malloc(sizeof(char) * 0)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * ((last - first) + 2))))
		return (NULL);
	while (first <= last)
		str[i++] = s1[first++];
	str[i] = '\0';
	return (str);
}
