##
## EPITECH PROJECT, 2022
## B-PSU-200-RUN-2-1-mysokoban-florian.dajon
## File description:
## Makefile
##

SRC	=	gets/get_objet.c\
		gets/get_map.c\
		gets/get_player.c\
		gets/get_boxes.c\
		moves/move_objet.c\
		moves/move_boxes.c\
		$(wildcard my/*.c)


IFLAGS	=	-I ../include

CFLAGS = -W -Wall -Werror -Wextra $(IFLAGS) -ggdb

OBJ	=	$(SRC:.c=.o)

NAME	=	libgame.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
