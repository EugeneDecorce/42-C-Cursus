# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 12:10:32 by edecorce          #+#    #+#              #
#    Updated: 2024/07/10 21:53:16 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
TEST = test
CC = gcc -g3

NOCFLAGS = -I/opt/homebrew/opt/readline/include
CFLAGS = -I/opt/homebrew/opt/readline/include -Wall -Wextra -Werror
LFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline
RM = rm -f

SOURCES = $(filter-out Tests/%, $(wildcard *.c */*.c))
SOURCES_TEST = $(filter-out Tests/random_tests.c main/%, $(wildcard *.c */*.c))
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_TEST = $(SOURCES_TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} $(CFLAGS) -o $(NAME) $(OBJECTS) $(LFLAGS)

clean:
	$(RM) $(OBJECTS) $(OBJECTS_TEST) a.out

fclean: clean
	$(RM) $(NAME) $(TEST)

re: fclean all

# Run tests:

norm: fclean
	norminette $(SOURCES)

noflag: fclean $(OBJECTS)
	${CC} $(NOCFLAGS) -o $(NAME) $(OBJECTS) $(LFLAGS)

test: fclean $(OBJECTS_TEST)
	${CC} $(NOCFLAGS) -o $(TEST) $(OBJECTS_TEST)  $(LFLAGS)
