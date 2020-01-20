/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 02:10:20 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 02:23:13 by esidelar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct			s_parce
{
	int					atoi_of_gestion;
	char				*gest;
	int					nb;
	int					temp;
	int					i;
	int					reset;
}						t_parce;

typedef struct			s_write
{
	char				*finish;
	char				*str;
}						t_write;

typedef struct			s_print
{
	int					i;
	int					minus;
	int					zero;
	int					point;
	long int			star;
	long int			star_two;
	char				*flags;
	char				*precision;
	char				*pf;
	char				*gestion;
	int					cheat;
	int					back_slash;
	va_list				list;
	struct s_write		x_write;
	struct s_parce		x_parce;
}						t_print;

typedef struct			s_norm
{
	long long int		larg;
	long long int		prec;
	long long int		temp;
	long long int		temp2;
	long long int		temp3;
	char				*chrtemp;
	long long int		i;
	long long int		nb;
	char				*str;
	long long int		ptr;
	char				verif;
}						t_norm;

int						ft_printf(const char *s, ...) __attribute__
((format(printf,1,2)));
void					sj_initialise_pt2(t_print *t);
void					sj_initialise(t_print *t);
void					sj_set(t_print *t);
void					sj_initialize_in_printf(t_print *t);

void					sj_ptr(t_print *t);
void					sj_csp(const char *s, t_print *t);
void					sj_dui(const char *s, t_print *t);
void					sj_x(const char *s, t_print *t);

int						sj_minfors(t_print *t);
int						sj_minfors_b(t_print *t, char *vide);
int						sj_minprecs(t_print *t);
int						sj_minprecs_loop(t_print *t, int i, int min);
void					sj_minus_for_c(t_print *t, t_norm *nor);

int						sj_minus(t_print *t);
long long int			sj_minus_reset(t_norm *nor);
void					sj_minus_a(t_print *t, t_norm *nor);
void					sj_minus_b(t_print *t, t_norm *nor);
void					sj_minus_c(t_print *t, t_norm *nor);

void					sj_not_flag_if(t_print *t, char *vide);
int						sj_not_flag(t_print *t);

void					sj_flags(const char *s, t_print *t);
void					sj_to_str(const char *s, t_print *t);
char					*sj_add_chr(char *s1, char const s2, int bck_slsh);
char					*sj_add_chr_b(char *s1, int bck_slsh, char *str);
void					sj_parsing(const char *s, t_print *t);

void					sj_flag_s(t_print *t);
void					sj_chr_of_point(t_print *t);
void					sj_else_not_chr_of_point(t_print *t);
int						sj_point_or_finish(t_print *t);
void					sj_reset_stuct(t_print *t);

int						sj_not_found_number(char *str);
void					sj_c_equal_zero(t_print *t);
int						sj_x_equal_zero(t_print *t);
void					sj_minus_and_point(t_print *t);
int						sj_forp(t_print *t);

void					sj_precision_to_finish(t_print *t);
int						sj_precision_to_finish_b(t_print *t);
void					sj_prec_and_flags(t_print *t);
int						sj_check_star(t_print *t, int i);
int						sj_check_star_pt2(t_print *t, int i, int reset);

void					sj_point_or_finish_c_and_zero(t_print *t);

void					sj_flag_s_b(t_print *t);
void					sj_point_or_finish_cut_one(t_print *t);
int						sj_point_or_finish_cut_tho(t_print *t);
int						sj_point_or_finish_cut_elif(t_print *t);
int						sj_point_or_finish_nb(t_print *t);

int						sj_parsing_percent(const char *s);

void					sj_main_printf(t_print *t, int i, const char *s);
char					*sj_free_add(char *str, char c);
char					*sj_temp_join(char *str, char *jn, int fre);
char					*sj_free_join(char *str, char *jn, int fre);

void					sj_reset_chr(t_print *t);

void					sj_to_pf(const char *s, t_print *t);
void					sj_stars(t_print *t);

void					sj_zero_to_finish(t_print *t);

#endif
