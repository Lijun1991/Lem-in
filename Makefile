# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 00:43:43 by lwang             #+#    #+#              #
#    Updated: 2017/06/12 23:21:58 by lwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = main.c helper.c validate_map1.c validate_map2.c print_map.c \
solve_adj_matrix.c get_path.c solve_move_ants.c free.c validate_map3.c 

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g -Ilibft
.PHONY: all clean fclean re

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

all: $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJ)

fclean:
	make -C ./libft fclean
	rm -f $(OBJ) $(NAME)

re: fclean $(NAME)
