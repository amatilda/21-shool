# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/01 21:18:43 by jkrypto           #+#    #+#              #
#    Updated: 2019/11/11 21:04:18 by jkrypto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libftprintf.a

SRC		=	ft_atoi.c						\
			ft_itoa.c						\
			ft_wcslen.c						\
			ft_wctomb.c						\
			ft_strchr.c						\
			ft_strcmp.c						\
			ft_strcpy.c						\
			ft_strlen.c						\
			ft_memset.c						\
			ft_gmtime_r.c					\
			ft_printf.c						\
			ft_snprintf.c					\
			ft_printf/fn_sp.c				\
			ft_printf/fn_big.c				\
			ft_printf/fn_str_copy.c			\
			ft_printf/fn_str_time.c			\
			ft_printf/fn_write_float.c		\
			ft_printf/fn_display.c			\
			ft_printf/fn_display_add.c		\
			ft_printf/fn_display_a.c		\
			ft_printf/fn_display_b.c		\
			ft_printf/fn_display_c.c		\
			ft_printf/fn_display_d.c		\
			ft_printf/fn_display_e.c		\
			ft_printf/fn_display_f.c		\
			ft_printf/fn_display_k.c		\
			ft_printf/fn_display_n.c		\
			ft_printf/fn_display_o.c		\
			ft_printf/fn_display_p.c		\
			ft_printf/fn_display_r.c		\
			ft_printf/fn_display_s.c		\
			ft_printf/fn_display_u.c		\
			ft_printf/fn_display_x.c		\
			ft_printf/fn_display_x_add.c	\
			ft_printf/fn_display_float.c	\
			ft_printf/fn_display_unknown.c	\
			ft_lnbr/ft_round.c				\
			ft_lnbr/ft_numtrim.c			\
			ft_lnbr/ft_numzero.c			\
			ft_lnbr/ft_longmath.c			\
			ft_lnbr/ft_parsenum.c

SDIR 	=	srcs/
DIRS 	=	srcs/ srcs/ft_printf/
SRCS	=	$(addprefix $(SDIR), $(SRC))
OBJS	=	$(patsubst %.c,%.o,$(SRCS))

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

%.o: %.c
	gcc $(FLAGS) $(OPFLAGS) -c $< -o $@ -MD

$(NAME): $(OBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)

all: $(OBJS) $(NAME)

clean:
	rm -f $(OBJS) $(patsubst %.c,%.d,$(SRCS))

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	clear
	@gcc $(FLAGS) test.c $(NAME) -o TEST
	@./TEST

pft:
	git clone https://github.com/gavinfielder/pft.git

include $(wildcard $(addsuffix *.d,$(DIRS)))

.PHONY: all clean fclean re
