# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 12:24:55 by edecorce          #+#    #+#              #
#    Updated: 2024/04/29 12:11:04 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
HEADER_DICT = philosophers.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES = $(wildcard *.c) $(wildcard */*.c)
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DICT) 

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all