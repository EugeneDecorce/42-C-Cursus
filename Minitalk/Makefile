# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 23:56:08 by edecorce          #+#    #+#              #
#    Updated: 2024/04/22 00:13:34 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
HEADER = minitalk.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVER_SOURCES = $(filter-out client.c, $(wildcard *.c))
CLIENT_SOURCES = $(filter-out server.c, $(wildcard *.c))
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJECTS)
	${CC} -o $(SERVER) $(SERVER_OBJECTS)

$(CLIENT): $(CLIENT_OBJECTS)
	${CC} -o $(CLIENT) $(CLIENT_OBJECTS)

clean:
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all