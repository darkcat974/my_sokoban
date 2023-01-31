##
## EPITECH PROJECT, 2022
## B-PSU-200-RUN-2-1-mysokoban-florian.dajon
## File description:
## Makefile
##

SRC	=	main.c\
		win_or_retry.c\
		loose.c

IFLAGS = -I ./include -L./lib -lgame -ggdb

CFLAGS = -g3 -lncurses -W -Wall -Werror -Wextra $(IFLAGS)

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib re
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	make -C ./lib clean
	rm -f $(OBJ)

fclean: clean
	make -C ./lib fclean
	rm -f $(NAME)

re: fclean all
