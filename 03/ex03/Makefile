# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:36:33 by edecorce          #+#    #+#              #
#    Updated: 2024/07/24 13:24:10 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap
HEADER_DIR = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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