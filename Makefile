# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 10:36:32 by deelliot          #+#    #+#              #
#    Updated: 2022/03/21 12:35:42 by trnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS = 1_main.c
SRCS += 2_validate_tetri.c
SRCS += 3_create_grid.c
SRCS += 4_translate_pieces.c
SRCS += 5_check_fit.c
SRCS += 6_solve.c
SRCS += ft_handle_errors.c

INCLS = fillit.h

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	gcc -c $(SRCS) $(CFLAGS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft

clean:
	rm -f $(OBJS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all fclean clean re
