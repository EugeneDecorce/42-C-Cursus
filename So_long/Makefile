# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:41:20 by edecorce          #+#    #+#              #
#    Updated: 2024/04/25 12:26:51 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h
MLX_DIR = mlx
MLX_LIB = -L$(MLX_DIR) -lmlx_Darwin -lmlx -framework OpenGL -framework AppKit -L/opt/X11/lib -lX11 -lXext
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES = $(shell find . -name "*.c")
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 


$(NAME): $(OBJECTS)
	$(CC) $(MLX_LIB) -o $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

