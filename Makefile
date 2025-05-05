##
## EPITECH PROJECT, 2025
## MinilibC
## File description:
## Assembly
##

.PHONY: all clean re fclean

SRC 	=	hello.c

OBJ 	=	 $(SRC:.c=.o)

NAME = test

TESTS_FLAGS	=	--coverage		\
				-lcriterion		\
NAMETEST = 	test

all: $(NAME)

tests_run:
		gcc -o $(NAMETEST) $(TESTS_FLAGS) tests/*.c
		./$(NAMETEST)
		-gcovr --exclude tests/ --txt-metric branch

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME)



clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		rm -rf $(NAMETEST)
		rm -rf *gcno
		rm -rf *gcda

re: fclean all
