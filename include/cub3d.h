/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sanjaro <sanjaro@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 04:08:27 by esidelar     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 02:28:58 by sanjaro     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

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

/*
**  _____  _____ ______  _   _  _____  _____
** /  ___||_   _|| ___ \| | | |/  __ \|_   _|
** \ `--.   | |  | |_/ /| | | || /  \/  | |
**  `--. \  | |  |    / | | | || |      | |
** /\__/ /  | |  | |\ \ | |_| || \__/\  | |
** \____/   \_/  \_| \_| \___/  \____/  \_/
*/

typedef struct	s_cub
{
	int			res_x;
	int			res_y;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	char		*path_sprit;
	int			f_color_r;
	int			f_color_g;
	int			f_color_b;
	int			c_color_r;
	int			c_color_g;
	int			c_color_b;
	int			help;
	char		*line_map;
	char		**tab_map;
	int			pc;
}				t_cub;

/*
**  _____  _   _ ______
** /  __ \| | | || ___ \
** | /  \/| | | || |_/ /
** | |    | | | || ___ \
** | \__/\| |_| || |_/ /
**  \____/ \___/ \____/
*/

int				sj_cub(int ac, char **gv);
void    		sj_cub_init(t_cub *cub);

/*
**  _____  _____ ______  _____ ______ ______
** /  ___||_   _||  _  \|  ___|| ___ \| ___ \
** \ `--.   | |  | | | || |__  | |_/ /| |_/ /
**  `--. \  | |  | | | ||  __| |    / |    /
** /\__/ /  | |  | |/ / | |___ | |\ \ | |\ \
** \____/   \_/  |___/  \____/ \_| \_|\_| \_|
*/

int				sj_stderr_argcub(int ac, char **gv, t_cub *cub);
void			sj_stderr_parcing(int nb);

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

int				sj_parse_no(char *line, t_cub *cub);
int				sj_parse_so(char *line, t_cub *cub);
int				sj_parse_we(char *line, t_cub *cub);
int				sj_parse_ea(char *line, t_cub *cub);
int				sj_parse_sprit(char *line, t_cub *cub);

int				sj_parse_f(char *line, t_cub *cub);
void			sj_parse_f2(char *line, t_cub *cub);

int				sj_parse_s(char *line, t_cub *cub);
void			sj_parse_s2(char *line, t_cub *cub);

int				sj_parsing_map(t_cub *cub, char *line);
char			*sj_parsing_linemap(char *line);
int				sj_count_map_line(char *line);
void			sj_clean_line(t_cub *cub);
int				sj_count_clean(t_cub *cub);

#endif
