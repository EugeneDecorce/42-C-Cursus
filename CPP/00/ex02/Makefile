# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 11:27:04 by edecorce          #+#    #+#              #
#    Updated: 2024/06/26 18:52:11 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
HEADER_DICT = .
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DICT)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all