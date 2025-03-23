##
## EPITECH PROJECT, 2025
## MinilibC
## File description:
## Assembly
##

.PHONY: all clean re fclean

SRC 	=	strlen.asm \
			strcmp.asm	\
			strchr.asm	\
			strrchr.asm	\
			memset.asm 	\
			strncmp.asm \
			strpbrk.asm	\
			strcspn.asm

OBJ 	=	 $(SRC:.asm=.o)

NAME = libasm.so

TESTS_FLAGS	=	--coverage		\
				-lcriterion		\

NAMETEST	=	unit_tests

all: $(NAME)

%.o: %.asm
	nasm -f elf64 -DPIC $< -o $@

$(NAME): $(OBJ)
		ld -shared $(OBJ) -o $(NAME)


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
