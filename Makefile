# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/10 09:32:01 by alidy        #+#   ##    ##    #+#        #
#    Updated: 2020/02/09 05:04:39 by esidelar    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #


NAMELIB = 	libft.a
NAME	= 	Cub3D
HEADERS	=	libft.h
CC		=	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

################################################################################
#								     LIBFT								   	   #
################################################################################

SRCSLIB	= 	libft/ft_printf.c \
			libft/srcs/sj_parce.c \
			libft/srcs/sj_pourcent.c \
			libft/srcs/sj_conversion.c \
			libft/srcs/sj_parce_main.c \
			libft/srcs/sj_parce_s_point_fin.c \
			libft/srcs/sj_parce_zero_mp.c \
			libft/srcs/sj_not_flag.c \
			libft/srcs/sj_zero.c \
			libft/srcs/sj_reset_char.c \
			libft/srcs/sj_minfors.c \
			libft/srcs/sj_minus.c \
			libft/srcs/sj_to_pf.c \
			libft/srcs/sj_part_two.c \
			libft/srcs/sj_part_three.c \
			libft/srcs/sj_printf_norm.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strlen.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strncmp.c \
			libft/ft_strlcpy.c \
			libft/ft_strlcat.c \
			libft/ft_strnstr.c \
			libft/ft_atoi.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putnbr_base.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_itoa_base.c \
			libft/ft_add_char.c \
			libft/ft_utoa_base.c \
			libft/ft_ltoa.c \
			libft/ft_strilen.c \
			libft/ft_neg_atoi.c \
			libft/ft_strllen.c \
			libft/ft_lltoa_base.c \
			libft/ft_douilled_putstr.c \
			libft/ft_utoi.c \
			libft/ft_strjoin_with_free.c \
			libft/get_next_line.c \
			libft/get_next_line_utils.c \
			libft/ft_ispace.c


################################################################################
#								      CUB3D									   #
################################################################################

SRCS =		main.c \
			srcs/sj_cub.c \
			srcs/sj_stderr.c \
			srcs/sj_cub_init.c \
			srcs/parsing_cub/sj_parsing.c \
			srcs/parsing_cub/sj_parsing_r.c \
			srcs/parsing_cub/sj_parsing_path.c \
			srcs/parsing_cub/sj_parsing_map.c \
			srcs/parsing_cub/sj_parsing_floor_and_ceiling.c \
			srcs/parsing_cub/sj_check_tab.c \
			srcs/sj_mlx/sj_windows.c \
			srcs/sj_mlx/sj_move.c \
			srcs/sj_mlx/sj_init_all_x_y.c \
			srcs/sj_mlx/sj_init_cast.c \
			srcs/sj_mlx/sj_color.c \
			srcs/sj_mlx/sj_draw.c \
			srcs/sj_mlx/sj_key.c \
			srcs/sj_mlx/sj_hit.c \
			srcs/sj_mlx/sj_view.c

OBJS	= 	$(SRCS:.c=.o)

OBJSLIB	= 	$(SRCSLIB:.c=.o)

all		: 	$(NAME)
			@echo "\033[1;33m          _____                    _____                    _____          \033[1;34m          _____                                   "
			@echo "\033[1;33m         /\    \                  /\    \                  /\    \         \033[1;34m         /\    \                  /\    \         "
			@echo "\033[1;33m        /::\    \                /::\____\                /::\    \        \033[1;34m        /::\    \                /::\    \        "
			@echo "\033[1;33m       /::::\    \              /:::/    /               /::::\    \       \033[1;34m       /::::\    \              /::::\    \       "
			@echo "\033[1;33m      /::::::\    \            /:::/    /               /::::::\    \      \033[1;34m      /::::::\    \            /::::::\    \      "
			@echo "\033[1;33m     /:::/\:::\    \          /:::/    /               /:::/\:::\    \     \033[1;34m     /:::/\:::\    \          /:::/\:::\    \     "
			@echo "\033[1;33m    /:::/  \:::\    \        /:::/    /               /:::/__\:::\    \    \033[1;34m    /:::/__\:::\    \        /:::/  \:::\    \    "
			@echo "\033[1;33m   /:::/    \:::\    \      /:::/    /               /::::\   \:::\    \   \033[1;34m   /::::\   \:::\    \      /:::/    \:::\    \   "
			@echo "\033[1;33m  /:::/    / \:::\    \    /:::/    /      _____    /::::::\   \:::\    \  \033[1;34m  /::::::\   \:::\    \    /:::/    / \:::\    \  "
			@echo "\033[1;33m /:::/    /   \:::\    \  /:::/____/      /\    \  /:::/\:::\   \:::\ ___\ \033[1;34m /:::/\:::\   \:::\    \  /:::/    /   \:::\ ___\ "
			@echo "\033[1;33m/:::/____/     \:::\____\|:::|    /      /::\____\/:::/__\:::\   \:::|    |\033[1;34m/:::/__\:::\   \:::\____\/:::/____/     \:::|    |"
			@echo "\033[1;33m\:::\    \      \::/    /|:::|____\     /:::/    /\:::\   \:::\  /:::|____|\033[1;34m\:::\   \:::\   \::/    /\:::\    \     /:::|____|"
			@echo "\033[1;33m \:::\    \      \/____/  \:::\    \   /:::/    /  \:::\   \:::\/:::/    / \033[1;34m \:::\   \:::\   \/____/  \:::\    \   /:::/    / "
			@echo "\033[1;33m  \:::\    \               \:::\    \ /:::/    /    \:::\   \::::::/    /  \033[1;34m  \:::\   \:::\    \       \:::\    \ /:::/    /  "
			@echo "\033[1;33m   \:::\    \               \:::\    /:::/    /      \:::\   \::::/    /   \033[1;34m   \:::\   \:::\____\       \:::\    /:::/    /   "
			@echo "\033[1;33m    \:::\    \               \:::\__/:::/    /        \:::\  /:::/    /    \033[1;34m    \:::\   \::/    /        \:::\  /:::/    /    "
			@echo "\033[1;33m     \:::\    \               \::::::::/    /          \:::\/:::/    /     \033[1;34m     \:::\   \/____/          \:::\/:::/    /     "
			@echo "\033[1;33m      \:::\    \               \::::::/    /            \::::::/    /      \033[1;34m      \:::\    \               \::::::/    /      "
			@echo "\033[1;33m       \:::\____\               \::::/    /              \::::/    /       \033[1;34m       \:::\____\               \::::/    /       "
			@echo "\033[1;33m        \::/    /                \::/____/                \::/____/        \033[1;34m        \::/    /                \::/____/        "
			@echo "\033[1;33m         \/____/                  ~~                       ~~              \033[1;34m         \/____/                  ~~              "
			@echo "\033[0m"

$(NAME)	:	$(OBJSLIB) $(OBJS)
		@echo "\033[1;33m"
		ar rcs $(NAMELIB) $(OBJSLIB)
		@echo "\033[0;34m"
		# make -C mlx re
		gcc $(CFLAGS) -g -lm libft.a mlx/libmlx.a $(OBJS) -o $(NAME) -framework OpenGL -framework Appkit
		@echo "\033[0m"

%.o: %.c $(HEADERS)
		clang $(FLAG) -c $< -o $@ -I $(HEADERS)

clean	:
		@echo "\033[1;31m"
		rm -f $(OBJSLIB) $(OBJS)
		@echo "\033[0m"
			
fclean	:	clean
		@echo "\033[1;31m"
		rm -f $(NAME)
		@echo "\033[0m"

re		: 	fclean all
