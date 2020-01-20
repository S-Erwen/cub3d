/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 02:42:38 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 03:44:15 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		lenerint(int n, char *base)
{
	long long	len;

	len = 0;
	if (n >= 0 && n <= 9)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n)
	{
		n /= ft_strlen(base);
		len++;
	}
	return (len);
}

char			*ft_itoa_base(long int n, char *base)
{
	char				*str;
	unsigned long int	tp;
	int					len;

	tp = (unsigned long int)n;
	len = lenerint(tp, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[tp % ft_strlen(base)];
		tp /= ft_strlen(base);
	}
	return (str);
}
