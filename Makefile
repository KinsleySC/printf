##
## EPITECH PROJECT, 2024
## Epitech
## File description:
## Makefile
##

NAME =	libmy.a
NAME2 =	unit_tests

SRC = 	$(shell find -name "*.c")

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run:
	gcc *.c tests/unit_test.c --coverage -lcriterion -o $(NAME2) -L. -lmy
	./$(NAME2)
	gcovr --exclude tests/

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcno
	rm -f *.gcda

re: fclean all
