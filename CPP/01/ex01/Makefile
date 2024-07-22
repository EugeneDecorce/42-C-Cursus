# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:36:33 by edecorce          #+#    #+#              #
#    Updated: 2024/06/28 09:14:18 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde
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
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all