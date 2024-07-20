NAME = minishell
TEST = test
CC = gcc -g3

NOCFLAGS = -I/opt/homebrew/opt/readline/include
CFLAGS = -I/opt/homebrew/opt/readline/include -Wall -Wextra -Werror
LFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline
RM = rm -f

SOURCES = $(shell find . -name "*.c" -type f)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	${CC} $(CFLAGS) -o $(NAME) $(OBJECTS) $(LFLAGS)

clean:
	$(RM) $(OBJECTS) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

