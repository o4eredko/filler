# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yochered <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 17:43:30 by yochered          #+#    #+#              #
#    Updated: 2018/12/15 17:43:32 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yochered.filler

SRC = $(addprefix $(SRCDIR), additional_funcs.c algorithm.c fill_map_layout.c find_funcs.c get_description.c)

SRCDIR = ./src/

BINARY = $(SRC:.c=.o)

LIBFT = libft.a

all: $(NAME)

$(NAME): $(BINARY) $(LIBFT)
	ar rc $(NAME) $(BINARY)

%.o: %.c
	gcc -Wall -W -Werror -c -o $@ $< -I ./includes/

$(LIBFT):
	make -C ./libft/

clean:
	/bin/rm -f $(BINARY)
	make -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: all clean
	mv yochered.filler ./resources
	chmod 777 resources/yochered.filler
	./resources/filler_vm -p1 resources/yochered.filler -p2 resources/players/carli.filler -f resources/maps/map00
