# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yochered <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 17:43:30 by yochered          #+#    #+#              #
#    Updated: 2018/12/19 18:00:24 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yochered.filler
LIBFT = libft.a
VISUAL = visu_filler

SRC = main.c additional_funcs.c algorithm.c fill_map_layout.c get_description.c
VISUAL_SRC = visu.c windows_funcs.c parse.c print.c

VISUAL_OBJ = $(VISUAL_SRC:.c=.o)
OBJ = $(SRC:.c=.o)

VISUAL_DIR = ./visu/
OBJ_DIR = ./obj/
SRCDIR = ./src/

all: $(NAME)

$(NAME): $(LIBFT) $(addprefix $(OBJ_DIR), $(OBJ))
	gcc -o $(NAME) $(addprefix $(OBJ_DIR), $(OBJ)) -L ./libft/ -lft -I ./includes/

filler: $(LIBFT) $(addprefix $(OBJ_DIR), $(VISUAL_OBJ))
	gcc -o $(VISUAL) $(addprefix $(OBJ_DIR), $(VISUAL_OBJ)) -L ./libft/ -lft -I /usr/local/include -lmlx -framework OpenGL -framework AppKit

$(addprefix $(OBJ_DIR), %.o): $(addprefix $(SRCDIR), %.c)
	gcc -Wall -W -Werror -c -o $@ $< -I ./includes/

$(addprefix $(OBJ_DIR), %.o): $(addprefix $(VISUAL_DIR), %.c)
	gcc -Wall -W -Werror -c -o $@ $< -I ./includes/

$(LIBFT):
	make -C ./libft/ --silent

clean:
	/bin/rm -f $(addprefix $(OBJ_DIR), $(OBJ) $(VISUAL_OBJ))
	make -C ./libft/ clean --silent

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(VISUAL)

re: fclean all

create: all filler
	/bin/rm -f res.txt
	./filler_vm -p2 ./$(NAME) -p1 players/carli.filler -f maps/map01 >> res.txt
