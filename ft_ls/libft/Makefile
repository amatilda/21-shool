# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 18:37:31 by jkrypto           #+#    #+#              #
#    Updated: 2019/10/07 21:08:49 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

DIRS		= srcs/
DIRS_D		= srcs/

LIST		=	ft_atoi.c		\
				ft_gmtime_r.c	\
				ft_itoa.c		\
				ft_memset.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_strndup.c	\
				ft_strcmp.c		\
				ft_strlen.c		\
				ft_wcslen.c		\
				ft_wctomb.c

SOURCE		= $(addprefix $(DIRS), $(LIST))
OBJ			= $(patsubst %.c,%.o,$(SOURCE))
INCLUDES	= includes/

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

all: $(OBJ) $(NAME)

debug:
	make OPFLAGS="-O0 -g"

test:
	make FLAGS=""

%.o: %.c
	gcc $(FLAGS) $(OPFLAGS) -I$(INCLUDES) -c $< -o $@ -MD

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(patsubst %.c,%.d,$(SOURCE))

fclean: clean
	rm -f $(NAME)

re: fclean all

include $(wildcard $(addsuffix *.d,$(DIRS_D)))

.PHONY: all clean fclean re debug test
