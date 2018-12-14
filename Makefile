NAME = yochered.filler
FLAGS = -c -Wall -W -Werror
SRC = main.c
SRCDIR = ./src/
INCDIR = ./includes/

all:
	gcc $(FLAGS) -o $(NAME) $(SRC)
