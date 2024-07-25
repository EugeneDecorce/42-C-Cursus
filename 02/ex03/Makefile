# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:36:33 by edecorce          #+#    #+#              #
#    Updated: 2024/07/24 11:01:51 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
HEADER_DIR = Fixed.hpp Point.hpp
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SOURCES = Fixed.cpp main.cpp Point.cpp
OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp $(HEADER_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER_DIR)
	${CPP} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all