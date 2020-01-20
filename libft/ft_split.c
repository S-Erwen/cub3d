/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 23:16:28 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 04:09:32 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	strs_char_len(char const *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (len);
		len++;
		i++;
	}
	return (len);
}

static size_t	u_detect(char const *s, char c, int u)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i] == c && s[i + 1] != c)
				u--;
			i++;
		}
		while (u == 0 && s[i])
		{
			len++;
			i++;
			if (s[i] == c)
				return (len);
		}
		i++;
	}
	return (len);
}

static char		**mal_char(int len, const char *s, int c, int error)
{
	char		**strs;

	len = strs_char_len(s, c);
	if (error)
	{
		if (!(strs = (char **)malloc(sizeof(char *) * 1)))
			return (NULL);
		strs[0] = 0;
	}
	else
	{
		if (!(strs = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
	}
	return (strs);
}

static char		**ft_spt_part_two(char c, char **strs, int i, const char *s)
{
	size_t		y;
	size_t		u;
	size_t		len;

	len = strs_char_len(s, c);
	u = 0;
	y = 0;
	while (len > 0)
	{
		if (s[i] == c && s[i])
		{
			strs[u][y] = '\0';
			u++;
			y = 0;
			if (!(strs[u] = malloc(sizeof(char) * (u_detect(s, c, u) + 1))))
				return (0);
			while (s[i] == c && s[i])
				i++;
		}
		strs[u][y++] = s[i++];
		len--;
	}
	strs[u][y] = '\0';
	strs[++u] = NULL;
	return (strs);
}

char			**ft_split(char const *s, char c)
{
	size_t		len;
	size_t		i;
	char		**strs;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	len = strs_char_len(s, c);
	if (!len || !s[i])
		return (strs = mal_char(len, s, c, 1));
	if (!(strs = mal_char(len, s, c, 0)))
		return (NULL);
	if (!(strs[0] = (char *)malloc(sizeof(char) * (u_detect(s, c, 0) + 1))))
		return (0);
	strs = ft_spt_part_two(c, strs, i, s);
	return (strs);
}
