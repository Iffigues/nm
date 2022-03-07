# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:37:32 by bordenoy          #+#    #+#              #
#    Updated: 2019/02/21 15:47:19 by bordenoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I 

SRC=	ft_bzero.c					\
		ft_memset.c					\
 		ft_putnbr.c					\
		ft_atoi.c					\
		ft_buffer.c					\
		ft_rest.c					\
		ft_float.c					\
		ft_pour.c					\
		ft_rot.c					\
		ft_floater.c				\
		ft_printf.c					\
		ft_putchar.c				\
		ft_nan.c					\
		ft_ret.c					\
		ft_putnbr_base.c			\
   		outil.c						\
		rat.c						\
		ft_println.c

OBJ=$(SRC:.c=.o)

$(NAME): ft_printf.h
		$(CC) $(CFLAGS) -c $(SRC) 
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean

