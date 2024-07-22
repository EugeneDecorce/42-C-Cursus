# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 11:27:04 by edecorce          #+#    #+#              #
#    Updated: 2024/07/22 17:18:58 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
HEADERS = .
CPP = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SOURCES = contact.cpp phonebook.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CPP} -o $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all