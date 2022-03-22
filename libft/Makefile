# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 13:04:07 by deelliot          #+#    #+#              #
#    Updated: 2022/03/21 12:24:52 by trnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

FUNCTIONS = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
	ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat \
	ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp \
	ft_strncmp ft_atoi ft_isuppercase ft_islowercase ft_isalpha ft_isdigit \
	ft_isalnum ft_isascii ft_isspace ft_isprint ft_toupper ft_tolower \
	ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri \
	ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
	ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr \
	ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew \
	ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstadd_back ft_lstmap \
	ft_strndup get_next_line ft_abs ft_memallocarray ft_sqrt ft_find_next_sqrt \
	ft_max ft_print_array


SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

SRCSD = $(foreach src, $(SRCS), $(addprefix ./, $(src)))

INCLS = libft.h

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

BIN_DIR = .

EXE := $(BIN_DIR)/$(NAME)

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) -I $(INCLS) $(CFLAGS)
	ar rc $(EXE) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all fclean clean re testcomp run retest

testcomp: re
	gcc $(FLAGS) $(INCLUDES) *test.c -L. -lft

run: testcomp
	./a.out

retest: fclean run

$(V).SILENT: