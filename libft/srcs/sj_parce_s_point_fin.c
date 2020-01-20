/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sj_parce_s_point_fin.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 16:36:49 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:38:17 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
**	++ IF %s (BEFORE THE POINT - AFTER) : I ADD SPACE
**	I ADD SPACE  : WHILE THE PREC BEFORE THE POINT IS BIGGER
**	THAN LEN OF STR
**	--┴-----------------------------------------------------------------
*/

void	sj_flag_s(t_print *t)
{
	int		space;
	int		le_s;

	space = ft_atoi(t->gestion) - ft_atoi(ft_strchr(t->gestion, '.') + 1);
	if (t->x_write.str[0] == '-')
		space--;
	le_s = ft_strlen(t->x_write.str);
	if (t->flags[0] == 's')
		sj_flag_s_b(t);
	while (0 < (t->x_parce.atoi_of_gestion - ft_strilen(t->x_write.str))
		&& t->x_parce.atoi_of_gestion > 0
		&& (ft_atoi(t->gestion) > ft_atoi(ft_strchr(t->gestion, '.') + 1))
		&& space && t->flags[0] != '%' && le_s < t->x_parce.atoi_of_gestion)
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
		t->x_parce.atoi_of_gestion--;
		space--;
	}
}

/*
**	┬----------------------------------------------------------------
**	|					//--> ADD '-' IF STR HAS
**	└-> LIKE FOR PREC AFTER POINT EXECPT FOR %s
**	WITH 0 INSTEAD SPACES
**
**	WHILE IF I FOUND A POINT IN GESTION
*/

void	sj_chr_of_point(t_print *t)
{
	char	*temp;

	if (ft_strchr(t->gestion, '.'))
	{
		sj_flag_s(t);
		t->x_parce.atoi_of_gestion = ft_atoi(ft_strchr(t->gestion, '.') + 1);
		if (t->x_write.str[0] == '-')
		{
			t->x_write.finish = sj_free_add(t->x_write.finish, '-');
			temp = ft_strdup(t->x_write.str + 1);
			free(t->x_write.str);
			t->x_write.str = ft_strdup(temp);
			free(temp);
		}
		while (0 < (t->x_parce.atoi_of_gestion - ft_strilen(t->x_write.str))
			&& t->x_parce.atoi_of_gestion > 0 && t->flags[0] != 's')
		{
			if (t->flags[0] != '%')
				t->x_write.finish = sj_free_add(t->x_write.finish, '0');
			t->x_parce.atoi_of_gestion--;
		}
	}
}

/*
**	IF FLAG == 'C' AND CHAR == '\0'
**	size-- AND ADD +1 FOR ret
*/

void	sj_else_not_chr_of_point(t_print *t)
{
	if (t->flags[0] == 'c' && t->x_write.str[0] == 0)
	{
		t->x_parce.atoi_of_gestion--;
		t->cheat++;
	}
	if (t->flags[0] == 'c' &&
		(t->x_write.str[0] == '0' || t->x_write.str[0] == 0))
		t->cheat--;
	while (0 < (t->x_parce.atoi_of_gestion - ft_strilen(t->x_write.str))
		&& t->x_parce.atoi_of_gestion > 0 && t->flags[0] != '%')
	{
		t->x_write.finish = sj_free_add(t->x_write.finish, ' ');
		t->x_parce.atoi_of_gestion--;
	}
	if (t->flags[0] == 'c' && t->x_write.str[0] == 0)
	{
		sj_reset_chr(t);
		t->cheat--;
	}
}

/*
**	IF IS STRING WITH PREC
**	THE REST OF SIZE OF GESTION AFTER FUNCTION BEHIND HERE
**	TO FINISH
**				---- IN ELSE IF ----
*/

/*
**	IF NB OF FLAG = {0}
**	IF PRES == NULL == ADD SPACE
*/

int		sj_point_or_finish(t_print *t)
{
	int		nb;

	if (t->flags[0] == 's' && t->point)
		sj_point_or_finish_cut_one(t);
	nb = sj_point_or_finish_cut_elif(t);
	if (!nb)
	{
		nb = sj_point_or_finish_nb(t);
		if (sj_not_found_number(t->x_write.str)
			&& (t->flags[0] == 'x' || t->flags[0] == 'X') && !nb)
		{
			t->x_write.finish = sj_free_join(t->x_write.finish, " ", 0);
			return (1);
		}
		else
			sj_point_or_finish_c_and_zero(t);
		return (0);
	}
	else if (nb == 2)
		return (0);
	else
		return (1);
}

void	sj_reset_stuct(t_print *t)
{
	if (t->x_parce.gest)
		free(t->x_parce.gest);
	if (t->gestion)
		free(t->gestion);
	t->gestion = NULL;
	if (t->flags)
		free(t->flags);
	t->flags = NULL;
	t->x_parce.nb = 0;
	t->x_parce.i = 0;
	t->x_parce.temp = 0;
	t->minus = 0;
	t->zero = 0;
	t->point = 0;
}
