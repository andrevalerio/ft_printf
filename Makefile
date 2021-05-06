# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 18:26:50 by avalerio          #+#    #+#              #
#    Updated: 2021/05/05 21:52:23 by avalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf_string.c ft_printf_char.c ft_printf_num.c ft_printf_negnum.c\
ft_printf_negnum2.c ft_printf_numtype.c ft_printf_ptr.c ft_printf_ux.c\
ft_printf_utils1.c ft_printf_utils2.c ft_printf_utils3.c ft_printf.c
OBJS = $(SRCS:%.c=%.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f

OBJ_PATH = $(addprefix ./obj/, $(OBJS))
INC_PATH = -I ./include
SRC_PATH = $(addprefix ./src/, $(SRCS))

all:	$(NAME)

$(NAME): 	$(OBJ_PATH)
	ar rcs $(NAME) $(OBJ_PATH)

$(OBJ_PATH):	$(SRC_PATH)
	$(CC) $(CFLAGS) $(INC_PATH) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re