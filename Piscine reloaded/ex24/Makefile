# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 08:49:13 by edecorce          #+#    #+#              #
#    Updated: 2024/05/14 08:50:12 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = srcs
INCLUDE = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

INCLUDE_SOURCES = ${INCLUDE}/
SOURCES = ${SRC}/ft_putchar.c \
			${SRC}/ft_swap.c \
			${SRC}/ft_putstr.c \
			${SRC}/ft_strlen.c \
			${SRC}/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ${INCLUDE}

all: $(NAME)

$(NAME): $(OBJECTS)
	${AR} $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all