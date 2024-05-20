# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 12:45:09 by edecorce          #+#    #+#              #
#    Updated: 2024/05/16 11:59:30 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
EXEC = ft_printf.c
SRC = utils
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SOURCES = utils/ft_putchar.c utils/ft_puthex.c utils/ft_putnbr_unsigned.c utils/ft_putnbr.c \
utils/ft_putpointer.c utils/ft_putstr.c utils/ft_tolower.c utils/ft_toupper.c ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ${HEADER}

all: $(NAME)

$(NAME): $(OBJECTS)
	${AR} $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

cclean: fclean
	$(RM) a.out

re: fclean all

compile: re
	$(CC) $(CFLAGS) $(EXEC) -L. $(NAME)
	./a.out

run: 
	$(CC) $(CFLAGS) $(EXEC) -L. $(NAME)
	@./a.out