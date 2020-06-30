# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 09:32:01 by esidelar          #+#    #+#              #
#    Updated: 2020/06/30 20:24:23 by esidelar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAMELIB = 	libft.a
NAME	= 	Cub3D
HEADERS	=	include/cub3d.h
CC		=	clang-9
CFLAGS 	= 	-Wall -Wextra -Werror
CLEAKS	=	-fsanitize=leak

################################################################################
#								      CUB3D									   #
################################################################################

SRCS =		main.c \
			srcs/sj_cub.c \
			srcs/sj_stderr.c \
			srcs/sj_cub_init.c \
			srcs/sj_ultimatefree.c \
			srcs/parsing_cub/sj_parsing.c \
			srcs/parsing_cub/sj_parsing_r.c \
			srcs/parsing_cub/sj_parsing_path.c \
			srcs/parsing_cub/sj_parsing_map.c \
			srcs/parsing_cub/sj_parsing_floor_and_ceiling.c \
			srcs/parsing_cub/sj_check_tab.c \
			srcs/parsing_cub/sj_check_path.c \
			srcs/parsing_cub/sj_addchr_for_map.c \
			srcs/parsing_cub/sj_line_to_str.c \
			srcs/parsing_cub/sj_map_add_fnrm.c \
			srcs/sj_mlx/sj_windows.c \
			srcs/sj_mlx/sj_move.c \
			srcs/sj_mlx/sj_init_all_x_y.c \
			srcs/sj_mlx/sj_init_cast.c \
			srcs/sj_mlx/sj_color.c \
			srcs/sj_mlx/sj_draw.c \
			srcs/sj_mlx/sj_key.c \
			srcs/sj_mlx/sj_hit.c \
			srcs/sj_mlx/sj_view.c \
			srcs/sj_sprite/sj_sprite.c \
			srcs/sj_sprite/sj_triforsprite.c \
			srcs/sj_bmp/sj_bmp.c

OBJS	= 	$(SRCS:.c=.o)

all		: 	$(NAMELIB) $(NAME)
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

$(NAMELIB):
			$(MAKE) -C libft all

$(NAME)	:	$(OBJS) $(HEADERS)
		@echo "\033[1;33m"
		$(MAKE) -C mlx re
		$(CC) $(OBJS) -I $(HEADERS) -g3 -L./mlx -lX11 -lXext -lmlx -lm -pthread -lbsd libft/libft.a -o $(NAME)
		@echo "\033[0m"

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) -g3 -c $< -o $@ -I $(HEADERS)

clean	:
		@echo "\033[1;31m"
		$(MAKE) -C libft clean
		$(MAKE) -C mlx clean
		rm -f $(OBJS)
		@echo "\033[0m"
			
fclean	:	clean
		@echo "\033[1;31m"
		$(MAKE) -C libft fclean
		$(MAKE) -C mlx clean
		rm -f $(NAME)
		rm -f 4deepthought/capture.bmp
		@echo "\033[0m"

re		: 	fclean all
