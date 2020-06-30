# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esidelar <esidelar@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 14:37:49 by esidelar          #+#    #+#              #
#    Updated: 2020/06/30 20:06:34 by esidelar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libft.a

CC		=	clang-9

SRCS	= 	ft_printf.c \
			srcs/sj_parce.c \
			srcs/sj_pourcent.c \
			srcs/sj_conversion.c \
			srcs/sj_parce_main.c \
			srcs/sj_parce_s_point_fin.c \
			srcs/sj_parce_zero_mp.c \
			srcs/sj_not_flag.c \
			srcs/sj_zero.c \
			srcs/sj_reset_char.c \
			srcs/sj_minfors.c \
			srcs/sj_minus.c \
			srcs/sj_to_pf.c \
			srcs/sj_part_two.c \
			srcs/sj_part_three.c \
			srcs/sj_printf_norm.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_base.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_itoa_base.c \
			ft_add_char.c \
			ft_utoa_base.c \
			ft_ltoa.c \
			ft_strilen.c \
			ft_neg_atoi.c \
			ft_strllen.c \
			ft_lltoa_base.c \
			ft_douilled_putstr.c \
			ft_utoi.c \
			ft_strjoin_with_free.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_ispace.c \

BONUS	=	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
			
HEADER 	= 	libft.h

OBJS 	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS:.c=.o} $(BONUS:.c=.o)

%.o: %.c $(HEADER)
		$(CC) -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@

$(NAME) : $(OBJS) $(OBJS_BONUS) $(HEADER)
		ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

all : $(NAME)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
