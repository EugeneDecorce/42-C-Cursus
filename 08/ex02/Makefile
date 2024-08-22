# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:36:33 by edecorce          #+#    #+#              #
#    Updated: 2024/08/05 14:22:19 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
HEADER_DIR = MutantStack.hpp
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SOURCES = main.cpp
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