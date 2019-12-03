# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 17:33:05 by jkrypto           #+#    #+#              #
#    Updated: 2019/09/20 21:49:32 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= fn_bruteforce.c		fn_validate.c			main.c
LIB 	= libft/libft.a
SRC_DIR	= srcs/
LIB_DIR	= libft/

LIB_ALL     = $(addsuffix .all,$(LIB_DIR))
LIB_DEBUG   = $(addsuffix .debug,$(LIB_DIR))
LIB_TEST    = $(addsuffix .test,$(LIB_DIR))
LIB_CLEAN   = $(addsuffix .clean,$(LIB_DIR))
LIB_FCLEAN  = $(addsuffix .fclean,$(LIB_DIR))

SOURCES		= $(addprefix $(SRC_DIR), $(SRC))
OBJECTS		= $(patsubst %.c,%.o,$(SOURCES))
INCLUDES	= $(addsuffix includes/,$(LIB_DIR))

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES) -MD

all:	$(NAME)

clean:	$(LIB_CLEAN)
	rm -f $(OBJECTS) $(wildcard $(addsuffix *.d,$(SRC_DIR)))

fclean:	$(LIB_FCLEAN) clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(LIB_ALL) $(OBJECTS) $(LIB)
	gcc $(FLAGS) $(OBJECTS) -o $(basename $(NAME)) $(LIB)

%.all:
	make -C $*

%.debug:
	make -C $* OPFLAGS="-O0 -g"

%.test:
	make -C $* FLAGS=""

%.clean:
	make -C $* clean

%.fclean:
	rm -f $(addsuffix *.a,$*)

include $(wildcard $(addsuffix *.d,$(SRC_DIR)))

.PHONY: all clean fclean re debug test
