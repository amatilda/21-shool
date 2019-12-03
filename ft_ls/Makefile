# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 18:36:06 by jkrypto           #+#    #+#              #
#    Updated: 2019/10/07 21:08:05 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIST	=	main.c						\
			ft_ls_main.c				\
			ft_ls_list_add_invalid.c	\
			ft_ls_list_add_file.c		\
			ft_ls_list_add_dir.c		\
			ft_ls_display.c				\
			ft_ls_display_full.c		\
			ft_ls_display_full_add.c	\
			ft_ls_write.c				\
			ft_ls_sort_strcmp.c			\
			ft_ls_sort_strcmp_add.c		\
			ft_ls_recursive.c			\
			ft_ls_recursive_add.c		\
			ft_ls_free.c

DIRS	=	src/
SOURCE	=	$(addprefix $(DIRS), $(LIST))
OBJ		=	$(patsubst %.c,%.o,$(SOURCE))

LIB		=	libft/libft.a
LDIRS	=	libft/

LIB_ALL		= $(addsuffix .all,$(LDIRS))
LIB_DEBUG	= $(addsuffix .debug,$(LDIRS))
LIB_TEST	= $(addsuffix .test,$(LDIRS))
LIB_CLEAN	= $(addsuffix .clean,$(LDIRS))
LIB_FCLEAN	= $(addsuffix .fclean,$(LDIRS))

INCS		= includes/
INCS_LIBFT	= $(addsuffix includes/,$(LDIRS))

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

clean: $(LIB_CLEAN)
	rm -f $(OBJ) $(wildcard $(addsuffix *.d,$(DIRS)))

fclean: $(LIB_FCLEAN) clean
	rm -f $(NAME)

re:		fclean all

%.o: %.c
	gcc $(FLAGS) $(OPFLAGS) -c $< -o $@ -I$(INCS_LIBFT) -I$(INCS) -MD

$(NAME): $(LIB_ALL) $(OBJ) $(LIB)
	gcc $(FLAGS) $(OPFLAGS) $(OBJ) -o $(basename $(NAME)) $(LIB)

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

include $(wildcard $(addsuffix *.d,$(DIRS)))

.PHONY: all clean fclean re debug test
