# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 22:23:41 by edecorce          #+#    #+#              #
#    Updated: 2024/06/24 14:43:19 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER_DICT = headers
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES = test.c check.c check2.c push_swap.c instructions/push.c instructions/reverse_rotate.c \
instructions/rotate.c instructions/swap.c quicksort/best_rotation.c quicksort/find_indexes.c \
quicksort/quicksort.c utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_lstadd_front.c \
utils/ft_lstdel_first.c utils/ft_lstdel_last.c utils/ft_lstlast.c utils/ft_lstnew.c \
utils/ft_lstsize.c utils/ft_strlen.c utils/ft_swap.c utils/ft_lstclear.c utils/ft_lstget_last.c \
utils/ft_contains.c utils/is_sorted.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@ -I $(HEADER_DICT)
# $(CFLAGS)
all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS) 
#$(HEADER_DICT)/push_swap.h.gch $(HEADER_DICT)/t_list.h.gch

fclean: clean
	$(RM) $(NAME)

compile: re all
	./$(NAME)

re: fclean all
