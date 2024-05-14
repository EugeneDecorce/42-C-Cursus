# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 00:32:24 by edecorce          #+#    #+#              #
#    Updated: 2024/04/11 00:49:11 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SOURCES = $(filter-out %_bonus.c, $(wildcard *.c))
BONUS_SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ${HEADER}

all: $(NAME)

$(NAME): $(OBJECTS)
	${AR} $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	${AR} $(NAME) $(BONUS_OBJECTS)

clean:
	$(RM) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all