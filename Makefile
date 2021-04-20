# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 18:26:50 by avalerio          #+#    #+#              #
#    Updated: 2021/04/07 22:10:27 by avalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_string.c ft_printf_char.c ft_printf_num.c \
ft_printf_negnum.c ft_printf_negnum2.c ft_printf_numtype.c ft_printf_ptr.c \
ft_printf_ux.c ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c
OBJS	= $(SRCS:%.c=%.o)
CC	= clang
CFLAGS	= -Wall -Wextra -Werror -c
NAME = libftprintf.a
RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re