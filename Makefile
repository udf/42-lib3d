# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 07:39:20 by mhoosen           #+#    #+#              #
#    Updated: 2018/07/27 10:01:19 by mhoosen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fast_trig map \
mat_copy mat_mult \
mat_set_identity mat_set_row \
mat_translate mat_scale mat_rotate \
mat_from_v3d p3d_transform p3d_project

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
	gcc -I includes -Ofast -o $@ $(@:tests/bin/%=tests/%.c) -L . -l3d -lm

re: fclean all
