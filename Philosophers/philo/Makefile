# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 12:24:55 by edecorce          #+#    #+#              #
#    Updated: 2024/07/07 00:10:17 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER_DICT = .
CC = gcc -g3
TFLAGS = #-fsanitize=thread -g -O1
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES = $(wildcard *.c) $(wildcard */*.c)
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(TFLAGS) -o $@ -I $(HEADER_DICT) 

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} $(TFLAGS) -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all