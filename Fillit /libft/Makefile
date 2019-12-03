# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 18:06:39 by jkrypto           #+#    #+#              #
#    Updated: 2019/09/20 18:41:06 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=	ft_lstadd.c				ft_putchar.c			ft_strdup.c		\
			ft_strnstr.c			ft_lstdel.c				ft_putchar_fd.c	\
			ft_strequ.c				ft_strrchr.c			ft_atoi.c		\
			ft_lstdelone.c			ft_putendl.c			ft_striter.c	\
			ft_strsplit.c			ft_bzero.c				ft_lstiter.c	\
			ft_putendl_fd.c			ft_striteri.c			ft_strstr.c		\
			ft_isalnum.c			ft_lstmap.c				ft_putnbr.c		\
			ft_strjoin.c			ft_strsub.c				ft_isalpha.c	\
			ft_lstnew.c				ft_putnbr_fd.c			ft_strlcat.c	\
			ft_strtrim.c			ft_isascii.c			ft_memalloc.c	\
			ft_putstr.c				ft_strlen.c				ft_swap.c		\
			ft_iscntrl.c			ft_memccpy.c			ft_putstr_fd.c	\
			ft_strmap.c				ft_tolower.c			ft_isdigit.c	\
			ft_memchr.c				ft_strcat.c				ft_strmapi.c	\
			ft_toupper.c			ft_isprint.c			ft_memcmp.c		\
			ft_strchr.c				ft_strncat.c			ft_wcslen.c		\
			ft_ispunct.c			ft_memcpy.c				ft_strclr.c		\
			ft_strncmp.c			ft_wctomb.c				ft_isspace.c	\
			ft_memdel.c				ft_strcmp.c				ft_strncpy.c	\
			ft_itoa.c				ft_memmove.c			ft_strcpy.c		\
			ft_strnequ.c			ft_itoa_base.c			ft_memset.c		\
			ft_strdel.c				ft_strnew.c

DIRS	= ./
SRCS	= $(addprefix $(DIRS), $(SRC))
OBJS	= $(patsubst %.c,%.o,$(SRCS))

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

all: $(OBJS) $(NAME)

debug:
	make OPFLAGS="-O0 -g"

test:
	make FLAGS=""

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -MD

$(NAME): $(OBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(wildcard $(addsuffix *.d,$(DIRS)))

fclean: clean
	rm -f $(NAME)

re: fclean all

include $(wildcard $(addsuffix *.d,$(DIRS)))

.PHONY: all clean fclean re debug test
