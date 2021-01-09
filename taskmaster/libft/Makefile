NAME		= libft.a
DIRS		= srcs/
LIST		= ft_atoi.c				\
			  ft_malloc.c			\
			  ft_strcmp.c			\
			  ft_strlen_utf8.c		\
			  ft_strndup.c			\
			  ft_utf8_decode.c		\
			  ft_crc32_mirror_one.c	\
			  ft_gmtime_r.c			\
			  ft_memcpy.c			\
			  ft_strdup.c			\
			  ft_strlen_utf8_litter.c\
			  ft_strsplit.c	\
			  ft_wcslen.c\
			  ft_crc32_tabl_mirror.c\
			  ft_memset.c	\
			  ft_strjoin.c	\
			  ft_strlen_utf8_n.c\
			  ft_strsplit_add.c\
			  ft_wctomb.c\
			  ft_free.c	\
			  ft_itoa.c\
			  ft_strchr.c	\
			  ft_strlen.c	\
			  ft_strncmp.c	\
			  ft_unicode_alpha.c\
			  ft_write_buffer.c\

SOURCE		= $(addprefix $(DIRS), $(LIST))
OBJ			= $(patsubst %.c,%.o,$(SOURCE))
D_FILE		= $(patsubst %.c,%.d,$(SOURCE))
INCLUDES	= includes/

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

all:
	@make -j $(NAME)

debug:
	@make -j OPFLAGS="-O0 -g"

test:
	@make -j FLAGS=""

%.o: %.c
	@gcc $(FLAGS) $(OPFLAGS) -I $(INCLUDES) -c $< -o $@ -MD

$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(D_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# При компеляции обьктых файлов создаються файлы соответсвий - тоесть что требеуться для компеляции данного сишного файла в обьктынй и при измененении одного из них заного скомпилируеться
-include $(D_FILE)

.PHONY: all clean fclean re debug test
