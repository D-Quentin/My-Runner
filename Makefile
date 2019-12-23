##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_hunter
##

SRC     =       my_runner.c		\

CPPFLAGS =	-I ./include

OBJ     =       $(SRC:.c=.o)

NAME    =       my_runner

all:		$(NAME)

$(NAME):        $(OBJ)
		make -C ./lib/my
		gcc -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm -o $(NAME) $(OBJ) $(CPPFLAGS) -L ./lib -lmy

clean:
		rm -f $(OBJ)

fclean:		clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:		fclean all
