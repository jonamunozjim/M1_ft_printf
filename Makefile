# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/29 17:24:54 by jmunoz-j          #+#    #+#              #
#    Updated: 2026/10/06 09:16:03 by jmunoz-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Var to compilator
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

## Var to files ft
SRC = utils/ft_putchar.c \
	utils/ft_putnbr_hex.c \
	utils/ft_putnbr_unsigned.c \
	utils/ft_putnbr.c \
	utils/ft_putptr.c \
	utils/ft_putstr.c \
	ft_printf.c \

OBJ = $(SRC:%.c=%.o)

## Rules
all: $(NAME)

## compile rule
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

## converting .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

## Remove rules
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
