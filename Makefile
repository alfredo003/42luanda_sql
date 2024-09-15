NAME = 42luanda_sql

CC = gcc

SRC = \
	./src/main.c \
	./src/database.c \
	./src/checker_comands.c \
	./src/util.c \

CFLAGS = -Wall -Wextra -Werror

HEADER = ./src/42luanda_sql.h

OBJS = $(SRC:.c=.o);

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

$(NAME): $(SRC)
		@$(CC) $(SRC) $(CFLAGS) -o $(NAME) 

all: $(NAME)

clean: 
	@rm -rf $(OBJS)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all
