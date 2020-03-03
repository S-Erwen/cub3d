/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esidelar <esidelar@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:08:27 by esidelar          #+#    #+#             */
/*   Updated: 2020/03/03 06:42:30 by esidelar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/libftprintf.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

# define HEIGHT height
# define WIDTH width

/*
**  _____  _____  _      _____ ______
** /  __ \|  _  || |    |  _  || ___ \
** | /  \/| | | || |    | | | || |_/ /
** | |    | | | || |    | | | ||    /
** | \__/\\ \_/ /| |____\ \_/ /| |\ \
**  \____/ \___/ \_____/ \___/ \_| \_|
*/

# define RED "\033[0;31m"
# define BOLD "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLDGREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BOLDYELLOW "\033[01;33m"
# define BLUE "\033[0;34m"
# define BOLDBLUE "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define BOLDMAGENTA "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLDCYAN "\033[1;36m"
# define RESET "\033[0m"

# define OXRED 0xFF0000
# define OXGREEN 0x0CFF00
# define OXYELLOW 0xFFF900
# define OXBLUE 0x0012FF
# define OXMAGENTA 0x8D00FF
# define OXCYAN 0x00FFF3
# define OXRESET 0xFFFFFF
# define OXSKY 0x008AFF
# define OXGROUND 0x95531D

# define C cub
# define K key
# define CS cast
# define SP sprite

/*
**  _   __ _______   _______
** | | / /|  ___\ \ / /  ___|
** | |/ / | |__  \ V /\ `--.
** |    \ |  __|  \ /  `--. \
** | |\  \| |___  | | /\__/ /
** \_| \_/\____/  \_/ \____/
*/

# define L_LEFT 0
# define L_DOWN 1
# define L_RIGHT 2
# define L_UP 13
# define R_LEFT 123
# define R_RIGHT 124
# define R_DOWN 125
# define R_UP 126
# define ESCAPE 53

/*
**  _____ ___________ _   _ _____ _____ _____
** /  ___|_   _| ___ \ | | /  __ \_   _/  ___|
** \ `--.  | | | |_/ / | | | /  \/ | | \ `--.
**  `--. \ | | |    /| | | | |     | |  `--. \
** /\__/ / | | | |\ \| |_| | \__/\ | | /\__/ /
** \____/  \_/ \_| \_|\___/ \____/ \_/ \____/
*/

typedef struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				mv_right;
	int				mv_left;
}					t_key;

typedef struct		s_recast
{	
	float			dir_x;
	float			dir_y;
	float			cam_plane_x;
	float			cam_plane_y;
	float			camera_x;
	float			raydir_x;
	float			raydir_y;
	float			pos_x;
	float			pos_y;
	float			time;
	float			oldtime;
	float			sidedistx;
	float			sidedisty;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	float			size_max_x;
	float			x;
	float			frametime;
	float			move_speed;
	float			rotation_speed;
	float			old_dir_x;
	float			oldcam_plane_x;
	char			*str;
	int				mapx;
	int				mapy;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
}					t_recast;

typedef struct		s_sprite
{
	int				*x;
	int				size;
	int				*y;
	int				nb_sp;
	void			*adrs_sp;
	float			*zbuffer;
	int				x_sp;
	int				y_sp;
	int				*txt_sp;
}					t_sprite;

typedef struct		s_cub
{
	int				up_c;
	int				up_f;
	int				xpm_x[4];
	int				xpm_y[4];
	int				*xpm_txt[4];
	void			*xpm_adrs[4];
	int				texnum;
	int				height;
	int				width;
	float			wallx;
	float			step;
	float			texpos;
	int				texx;
	int				texy;
	float			dbl_pos_x;
	float			dbl_pos_y;
	char			pos;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_sprit;
	char			*line_map;
	char			**tab_map;
	void			*mlx;
	void			*windows;
	void			*img_ptr;
	int				res_x;
	int				res_y;
	int				init_pos_x;
	int				init_pos_y;
	int				f_color_r;
	int				f_color_g;
	int				f_color_b;
	int				c_color_r;
	int				c_color_g;
	int				c_color_b;
	int				help;
	int				pc;
	int				x;
	int				y;
	int				bpp;
	int				size_line;
	int				endian;
	int				*img_data;
	t_sprite		*sprite;
	t_key			*key;
	t_recast		*cast;
}					t_cub;

/*
**  _____  _   _ ______
** /  __ \| | | || ___ \
** | /  \/| | | || |_/ /
** | |    | | | || ___ \
** | \__/\| |_| || |_/ /
**  \____/ \___/ \____/
*/

int				sj_cub(int ac, char **gv);
void			sj_cub_init(t_cub *cub);
void			sj_cub_free(t_cub *cub);
void			sj_init_player(t_cub *cub);

void			sj_cub_init(t_cub *cub);
void			sj_cub_init_ii(t_cub *cub);
void			sj_cub_init_iii(t_cub *cub);
void			sj_cub_init_iv(t_cub *cub);

/*
**  _____  _____ ______  _____ ______ ______
** /  ___||_   _||  _  \|  ___|| ___ \| ___ \
** \ `--.   | |  | | | || |__  | |_/ /| |_/ /
**  `--. \  | |  | | | ||  __| |    / |    /
** /\__/ /  | |  | |/ / | |___ | |\ \ | |\ \
** \____/   \_/  |___/  \____/ \_| \_|\_| \_|
*/

int				sj_stderr_argcub(int ac, char **gv, t_cub *cub);
void			sj_stderr_parsing(int nb);
void			sj_stderr_parsing_tho(int nb);

/*
** ______   ___  ______  _____  _____  _   _  _____
** | ___ \ / _ \ | ___ \/  ___||_   _|| \ | ||  __ \
** | |_/ // /_\ \| |_/ /\ `--.   | |  |  \| || |  \/
** |  __/ |  _  ||    /  `--. \  | |  | . ` || | __
** | |    | | | || |\ \ /\__/ / _| |_ | |\  || |_\ \
** \_|    \_| |_/\_| \_|\____/  \___/ \_| \_/ \____/
*/

int				sj_parse_all(t_cub *cub, char **gv);
int				sj_gnl_parse(char *line, t_cub *cub);
int				sj_parse_letter(char *line, t_cub *cub);
int				sj_parse_letter_p2(char *line, t_cub *cub);

int				sj_parse_r(char *line, t_cub *cub);
int				sj_res(char *line, t_cub *cub, int i);

int				sj_parse_no(char *line, t_cub *cub);
int				sj_parse_so(char *line, t_cub *cub);
int				sj_parse_we(char *line, t_cub *cub);
int				sj_parse_ea(char *line, t_cub *cub);
int				sj_parse_sprit(char *line, t_cub *cub);

int				sj_parse_f(char *line, t_cub *cub);
int				sj_parse_f2(char *line, t_cub *cub);

int				sj_parse_c(char *line, t_cub *cub);
int				sj_parse_c2(char *line, t_cub *cub);

void			sj_clean_line(t_cub *cub);
char			*sj_parsing_linemap(char *line);
int				sj_parsing_map(t_cub *cub, char *line);
int				sj_count_map_line(char *line);
int				sj_count_clean(t_cub *cub);

int				sj_check_tab(t_cub *cub);
int				sj_ckeck_double_local(t_cub *cub);
int				sj_ckeck_double_local_tho(t_cub *cub);
int				sj_space_skip(char *str);
int				sj_first_line(char *str);

int				sj_check_path(t_cub *cub);

/*
** ___  ___ _     __   __
** |  \/  || |    \ \ / /
** | .  . || |     \ V /
** | |\/| || |     /   \
** | |  | || |____/ /^\ \
** \_|  |_/\_____/\/   \/
*/

void			sj_creat_new_windows(t_cub *cub);
float			sj_abs(float nb);
int				sj_close(void);
int				sj_dda(t_cub *cub);
int				sj_key_press(int key, t_cub *cub);
int				sj_key_release(int key, t_cub *cub);
int				sj_move(t_cub *cub);

void			sj_key_down(t_cub *cub);
void			sj_key_right(t_cub *cub);
void			sj_key_left(t_cub *cub);
void			sj_key_up(t_cub *cub);

void			sj_key_mv_left(t_cub *cub);
void			sj_key_mv_right(t_cub *cub);

void			sj_init_start_dda(t_cub *cub);
void			sj_raydir_step(t_cub *cub);
void			sj_hit_dist(t_cub *cub);
void			sj_time(t_cub *cub);

void			sj_init_cast(t_cub *cub);
void			sj_init_image(t_cub *cub);
void			sj_get_adrs(t_cub *cub);
void			sj_dir_init(t_cub *cub);

int				sj_color(int r, int g, int b);

void			sj_draw_start_end(t_cub *cub);
void			sj_draw(t_cub *cub);
void			sj_draw_texture(t_cub *cub);

void			sj_hit(t_cub *cub);

void			sj_sprite(t_cub *cub);
int				sj_tab_sprite(t_cub *cub);

void			ult_i_to_vii(int ret, t_cub *cub);
void			ult_vii_to_xii(int ret, t_cub *cub);

#endif
