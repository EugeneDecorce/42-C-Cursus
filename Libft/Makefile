# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 00:32:24 by edecorce          #+#    #+#              #
#    Updated: 2024/05/16 09:44:06 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = .
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SOURCES = ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
ft_bzero.c ft_itoa.c ft_memset.c ft_strdup.c ft_strncmp.c \
ft_calloc.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
ft_isalnum.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
ft_isalpha.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c
BONUS_SOURCES = $(SOURCES) ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstadd_back.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstclear.c ft_lstdelone.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ${HEADER}

all: $(NAME)

$(NAME): $(OBJECTS)
	${AR} $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
	${AR} $(NAME) $(BONUS_OBJECTS)

clean:
	$(RM) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(BONUS_SOURCES)
# 	gcc -nostartfiles -shared -o libft.so $(BONUS_OBJECTS)