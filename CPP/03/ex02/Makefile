# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:36:33 by edecorce          #+#    #+#              #
#    Updated: 2024/07/17 11:50:37 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap
HEADER_DICT = .
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@ -I $(HEADER_DICT)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS) *.replace

fclean: clean
	$(RM) $(NAME)

re: fclean all