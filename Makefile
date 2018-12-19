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

SRC = $(addprefix $(SRCDIR), main.c additional_funcs.c algorithm.c fill_map_layout.c get_description.c)

VISUAL_SRC = $(addprefix $(VISUAL_DIR), visualize.c stdfuncs.c)

VISUAL_DIR = ./visualizer/

VISUAL_OBJ = $(VISUAL_SRC:.c =.o)

SRCDIR = ./src/

OBJ = $(SRC:.c=.o)

LIBFT = libft.a

VISUAL = show_filler

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@gcc -o $(NAME) $(SRC) -L ./libft/ -lft -I ./includes/

filler: $(VISUAL_OBJ) $(LIBFT)
	@gcc -o show_filler $(VISUAL_OBJ) -L ./libft/ -lft -lncurses -I ./includes/

$(addprefix $(SRCDIR), %.o): $(addprefix $(SRCDIR), %.c)
	@gcc -Wall -W -Werror -c -o $@ $< -I ./includes/

$(addprefix $(VISUAL_DIR), %.o): $(addprefix $(VISUAL_DIR), %.c)
	@gcc -Wall -W -Werror -c -o $@ $< -I -I ./includes/

$(LIBFT):
	@make -C ./libft/ --silent

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(VISUAL_OBJ)
	@make -C ./libft/ clean --silent

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(VISUAL)

re: fclean all

create: all filler
	/bin/rm -f res.txt
	./filler_vm -p2 ./$(NAME) -p1 players/carli.filler -f maps/map01 >> res.txt
