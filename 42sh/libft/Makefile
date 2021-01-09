NAME		= libft.a
DIRS		= srcs/
LIST		=	ft_atoi.c\
				ft_crc32_tabl_mirror.c\
				ft_crc32_mirror_one.c\
				ft_gmtime_r.c\
				ft_itoa.c\
				ft_malloc.c\
				ft_free.c\
				ft_memset.c\
				ft_memcpy.c\
				ft_strjoin.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strndup.c\
				ft_strcmp.c\
				ft_strncmp.c\
				ft_strlen.c\
				ft_unicode_alpha.c\
				ft_utf8_decode.c\
				ft_strlen_utf8.c\
				ft_strlen_utf8_n.c\
				ft_strlen_utf8_litter.c\
				ft_strsplit.c\
				ft_wcslen.c\
				ft_wctomb.c\
				ft_write_buffer.c
SOURCE		= $(addprefix $(DIRS), $(LIST))
OBJ			= $(patsubst %.c,%.o,$(SOURCE))
D_FILE		= $(patsubst %.c,%.d,$(SOURCE))
INCLUDES	= includes/

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

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
	rm -f $(OBJ) $(D_FILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

# При компеляции обьктых файлов создаються файлы соответсвий - тоесть что требеуться для компеляции данного сишного файла в обьктынй и при измененении одного из них заного скомпилируеться
-include $(D_FILE)

.PHONY: all clean fclean re debug test
