# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yochered <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/26 13:59:12 by yochered          #+#    #+#              #
#    Updated: 2018/12/14 10:04:18 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
	ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c\
	ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
	ft_strtrim.c ft_strsplit.c ft_count_digits.c ft_itoa.c ft_putchar.c ft_putstr.c\
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
	ft_lstmap.c ft_itoa_base.c ft_lstrev.c ft_cycle_detector.c ft_print_memory.c\
	get_next_line.c ft_printf.c $(addprefix ./printf_src/, $(PRINTF))

PRINTF = convert_to_str.c handlers.c function_array.c print_int.c\
	print_pointer.c print_str.c str_functions.c mem_funcs.c allowed_symbols.c\
	print_uint.c print_float.c bonus_types.c print_funcs.c

BINARY = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINARY)
	ar rc $(NAME) $(BINARY)

%.o: %.c
	gcc -Wall -W -Werror -c -o $@ $< -I ./includes/

clean:
	/bin/rm -f $(BINARY)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
