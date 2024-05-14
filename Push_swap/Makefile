# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 22:23:41 by edecorce          #+#    #+#              #
#    Updated: 2024/04/21 01:30:19 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER_DICT = headers
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES = $(wildcard *.c) $(wildcard */*.c)
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DICT) 
#$(CFLAGS)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

compile: re all
	./$(NAME)

re: fclean all
