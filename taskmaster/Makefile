# Имя выходного файла
NAME = taskmaster

#Путь к текущей папке
#PWD = $(shell pwd)

#Списки включаемых файлов
include amatilda.mak
LIST = $(AMATILDA)

# Все деректории в которых будим искать си файлы для компиляции
DIRS		= srcs/

# Получаем Список обькектных файлов которые должны быть или иначе создаем
SOURCE		= $(addprefix $(DIRS), $(LIST))
OBJ			= $(patsubst %.c,%.o,$(SOURCE))
D_FILE		= $(patsubst %.c,%.d,$(SOURCE))

# Список дериктории для библиотек
LIB_DIRS        = libft/ conf_reader/

# Список файлов с биоблитек которые подключаем при компиляции
LIB 	   		= libft/libft.a  conf_reader/conf_reader.a

# Для удобства и универсальности что бы обработать биоблитеки с помощью ихнего MakeFile
LIB_CMD_ALL     = $(addsuffix .all,$(LIB_DIRS))
LIB_CMD_DEBUG   = $(addsuffix .debug,$(LIB_DIRS))
LIB_CMD_TEST    = $(addsuffix .test,$(LIB_DIRS))
LIB_CMD_CLEAN   = $(addsuffix .clean,$(LIB_DIRS))
LIB_CMD_FCLEAN  = $(addsuffix .fclean,$(LIB_DIRS))

# Список папок биоблитек с которых берем хедары
INCLUDES		= -I includes/ 
INCLUDES_LIBFT	= $(addprefix -I ,$(addsuffix includes/,$(LIB_DIRS)))

# Флаги компиляции по умолчанию
override OPFLAGS ?= -O2
override FLAGS	?= -Wall -Wextra -Werror

DELTA			= $$(echo "$$(tput cols)-47"|bc)
NB				= $(words $(SOURCE))
INDEX			= 0

# Самое первое правило которое действует по умолчанию
all:
	@make  $(NAME)

# Команда которая компирует отладочную версию
debug: $(LIB_CMD_DEBUG)
	@make  OPFLAGS="-O0 -g"

# Команда которая компирует не вызывая минимум сообщений об ошибках
test: $(LIB_CMD_TEST)
	@make  FLAGS=""

# Удалим все обьктные файлы созданые нами
clean: $(LIB_CMD_CLEAN)
	@rm -f $(OBJ) $(D_FILE)
	@printf "\r\033[38;5;202m✖  clean $(NAME)\033[0m\033[K\n"

# Удалим финальный файл
fclean: $(LIB_CMD_FCLEAN) clean
	@rm -f $(NAME)
	@printf "\r\033[38;5;196m❌ fclean $(NAME)\033[0m\033[K\n"

# Очистим все и скомпилируем заново
re: fclean all

# Правило которое если нету обьктного файла соответсвуещего сишному файлу или сищный файл изменился тогда скомпилируем обьктный файл
%.o: %.c
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval COLOR=$(shell echo $$(($(PERCENT)%35+196))))
	@$(eval TO_DO=$(shell echo $$((20-$(INDEX)*20/$(NB)))))
	@printf "\r\033[38;5;11m⌛ MAKE %10.10s : %2d%% \033[48;5;%dm%*s\033[0m%*s\033[48;5;255m \033[0m \033[38;5;11m%*.*s\033[0m\033[K" $(NAME) $(PERCENT) $(COLOR) $(DONE) "" $(TO_DO) "" $(DELTA) $(DELTA) "$@"
	@gcc $(FLAGS) $(OPFLAGS) -c $< -o $@ $(INCLUDES_LIBFT) $(INCLUDES) -MMD
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

# Если обьктынй файл или биоблитека изменилась занова перекомпилируем выходной файл
$(NAME): $(OBJ) $(LIB)
	@gcc $(FLAGS) $(OPFLAGS) $(OBJ) -o $(basename $(NAME)) $(LIB)
	@strip -x $@
	@printf "\r\033[48;5;15;38;5;25m✅   MAKE $(NAME)\033[0m\033[K\n"

# Если в  makefile  юзаеться make name то тут проверяем изменения в биоблетеках всех
$(LIB): $(LIB_CMD_ALL)

# Правило которое соответсвует $(LIB_CMD_ALL)
%.all:
	@make  -C $*

# Правило которое соответсвует $(LIB_CMD_DEBUG) ......
%.debug:
	@make  -C $* OPFLAGS="-O0 -g"

%.test:
	@make  -C $* FLAGS=""

%.clean:
	@make  -C $* clean

%.fclean:
	@rm -f $(addsuffix *.a,$*)

# При компеляции обьктых файлов создаються файлы соответсвий - тоесть что требеуться для компеляции данного сишного файла в обьктынй и при измененении одного из них заного скомпилируеться
-include $(D_FILE)

# Список используемых команд в MakeFile что бы не спутало с файлами в каталоге
PHONY: all clean fclean re debug test
