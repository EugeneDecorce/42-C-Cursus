# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 12:10:32 by edecorce          #+#    #+#              #
#    Updated: 2024/04/30 08:43:15 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -I/opt/homebrew/opt/readline/include # -Wall -Wextra -Werror 
LFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline
RM = rm -f

SOURCES = $(wildcard *.c) $(wildcard */*.c)
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} -o $(NAME) $(OBJECTS) $(LFLAGS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all