/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strllen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 07:31:14 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 03:47:00 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

long unsigned int		ft_strllen(const char *s)
{
	long unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}