# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecorce <edecorce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 00:32:24 by edecorce          #+#    #+#              #
#    Updated: 2024/05/15 18:14:26 by edecorce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = .
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

ALL_SOURCES = ft_isdigit.c ft_lstiter_bonus.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
ft_atoi.c ft_isprint.c ft_lstlast_bonus.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
ft_bzero.c ft_itoa.c ft_lstmap_bonus.c ft_memset.c ft_strdup.c ft_strncmp.c \
ft_calloc.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
ft_isalnum.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
ft_isalpha.c ft_lstclear_bonus.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
ft_isascii.c ft_lstdelone_bonus.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c

SOURCES = $(filter-out %_bonus.c, $(ALL_SOURCES))
BONUS_SOURCES = $(ALL_SOURCES)
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