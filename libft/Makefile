# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: esidelar <esidelar@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 14:37:49 by esidelar     #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 06:43:57 by esidelar    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME 	= 	libft.a

SRCS 	= 	ft_memset.c \
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
			ft_ispace.c

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

%.o: %.c Makefile $(HEADER)
		gcc -Wall -Wextra -Werror -I include -c $< -o $@

$(NAME) : $(OBJS) $(HEADER)
		ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus: $(OBJS_BONUS) $(HEADER)
		ar rc $(NAME) $(OBJS_BONUS)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
