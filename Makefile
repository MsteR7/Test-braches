##
## EPITECH PROJECT, 2025
## MinilibC
## File description:
## Assembly
##

.PHONY: all clean re fclean

SRC 	=	hello.c \

OBJ 	=	 $(SRC:.asm=.o)

NAME = test

TESTS_FLAGS	=	--coverage		\
				-lcriterion		\

NAMETEST	=	unit_tests

all: $(NAME)


$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME)


tests_run:
		gcc -o $(NAMETEST) $(TESTS_FLAGS) tests/*.c
		./$(NAMETEST)
		-gcovr --exclude tests/ --txt-metric branch

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		rm -rf $(NAMETEST)
		rm -rf *gcno
		rm -rf *gcda

re: fclean all
