##
## EPITECH PROJECT, 2024
## Epitech
## File description:
## Makefile
##

NAME =	libmy.a

SRC = 	$(shell find -name "*.c")

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:
	rm -f $(NAME)

re: fclean all
