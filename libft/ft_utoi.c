/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 09:24:37 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 09:25:59 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int		ft_utoi(const char *nptr)
{
	long	nb;
	long	i;

	i = 0;
	nb = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i++] - 48;
	}
	return (nb);
}
