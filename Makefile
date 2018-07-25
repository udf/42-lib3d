# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 07:39:20 by mhoosen           #+#    #+#              #
#    Updated: 2018/07/25 15:44:45 by mhoosen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fast_trig \
mat_copy mat_mult v3d_transform \
mat_set_identity mat_set_row \
mat_translate mat_scale \
mat_rotate

NAME=lib3d.a
INCLUDES=lib3d.h
HEADERS=$(INCLUDES:%=includes/%)
OBJS=$(SRCS:=.o)

TEST_SRCS=$(wildcard tests/t_*.c)
TEST_BINS=$(TEST_SRCS:tests/%.c=tests/bin/%)

CFLAGS=-Wall -Wextra -Werror -Wconversion

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

$(OBJS): %.o:srcs/%.c $(HEADERS)
	gcc $(CFLAGS) -I includes -c $(@:%.o=srcs/%.c)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

tests: $(TEST_BINS)

$(TEST_BINS): $(NAME) $(TEST_SRCS)
	mkdir -p ./tests/bin
	gcc -I includes -o $@ $(@:tests/bin/%=tests/%.c) -L . -lft -lm

re: fclean all
