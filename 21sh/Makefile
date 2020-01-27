# Имя выходного файла
NAME = 21sh

#Путь к текущей папке
#PWD = $(shell pwd)

#Списки включаемых файлов
include amatilda.mak pguitar.mak
LIST = $(AMATILDA) $(PGUITAR)

# Все деректории в которых будим искать си файлы для компиляции
DIRS		= srcs/
# Получаем Список обькектных файлов которые должны быть или иначе создаем
SOURCE		= $(addprefix $(DIRS), $(LIST))
OBJ			= $(patsubst %.c,%.o,$(SOURCE))
D_FILE		= $(patsubst %.c,%.d,$(SOURCE))

# Список дериктории для библиотек
LIB_DIRS        = libft/
# Список файлов с биоблитек которые подключаем при компиляции
LIB 	   		= libft/libft.a

# Для удобства и универсальности что бы обработать биоблитеки с помощью ихнего MakeFile
LIB_CMD_ALL     = $(addsuffix .all,$(LIB_DIRS))
LIB_CMD_DEBUG   = $(addsuffix .debug,$(LIB_DIRS))
LIB_CMD_TEST    = $(addsuffix .test,$(LIB_DIRS))
LIB_CMD_CLEAN   = $(addsuffix .clean,$(LIB_DIRS))
LIB_CMD_FCLEAN  = $(addsuffix .fclean,$(LIB_DIRS))

# Список папок биоблитек с которых берем хедары
INCLUDES		= includes/
INCLUDES_LIBFT	= $(addsuffix includes/,$(LIB_DIRS))

# Флаги компиляции по умолчанию
override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror

# Самое первое правило которое действует по умолчанию
all: $(LIB_CMD_ALL) $(NAME)

# Команда которая компирует отладочную версию
debug: $(LIB_CMD_DEBUG)
	make OPFLAGS="-O0 -g"

# Команда которая компирует не вызывая минимум сообщений об ошибках
test: $(LIB_CMD_TEST)
	make FLAGS=""

# Удалим все обьктные файлы созданые нами
clean: $(LIB_CMD_CLEAN)
	rm -f $(OBJ) $(D_FILE)

# Удалим финальный файл
fclean: $(LIB_CMD_FCLEAN) clean
	rm -f $(NAME)

# Очистим все и скомпилируем заново
re: fclean all

# Правило которое если нету обьктного файла соответсвуещего сишному файлу или сищный файл изменился тогда скомпилируем обьктный файл
%.o: %.c
	gcc $(FLAGS) $(OPFLAGS) -c $< -o $@ -I$(INCLUDES_LIBFT) -I$(INCLUDES) -MD

# Если обьктынй файл или биоблитека изменилась занова перекомпилируем выходной файл
$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $(OPFLAGS) $(OBJ) -o $(basename $(NAME)) $(LIB)

# Правило которое соответсвует $(LIB_CMD_ALL)
%.all:
	make -C $*

# Правило которое соответсвует $(LIB_CMD_DEBUG) ......
%.debug:
	make -C $* OPFLAGS="-O0 -g"

%.test:
	make -C $* FLAGS=""

%.clean:
	make -C $* clean

%.fclean:
	rm -f $(addsuffix *.a,$*)

# При компеляции обьктых файлов создаються файлы соответсвий - тоесть что требеуться для компеляции данного сишного файла в обьктынй и при измененении одного из них заного скомпилируеться
include $(wildcard $(D_FILE))

# Список используемых команд в MakeFile что бы не спутало с файлами в каталоге
.PHONY: all clean fclean re debug test
