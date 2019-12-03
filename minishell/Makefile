# Имя выходного файла и проверка на расширение для Windows
NAME = minishell

LIST		=	main.c\
				auto/ft_42sh_auto_create.c\
				auto/ft_42sh_auto_free_all_cmd.c\
				auto/ft_42sh_auto_cmd.c\
				auto/ft_42sh_auto_dsp_cmd.c\
				auto/ft_42sh_auto_dsp_next_cmd.c\
				auto/ft_42sh_auto_limit.c\
				dq/ft_42sh_dq_add.c\
				dq/ft_42sh_dq_combi_date.c\
				dq/ft_42sh_dq.c\
				dq/ft_42sh_dq_test.c\
				dq/ft_42s_dq_split.c\
				exe/ft_42sh_exe.c\
				dsp/ft_42sh_display.c\
				dsp/ft_42sh_dsp_caret.c\
				dsp/ft_42sh_dsp_caret_raw.c\
				dsp/ft_42sh_dsp_test.c\
				dsp/ft_42sh_dsp_caret_left.c\
				dsp/ft_42sh_dsp_caret_right.c\
				dsp/ft_42sh_dsp_caret_correct.c\
				list/ft_42sh_list_sort_paste.c\
				list/ft_42sh_list_cut.c\
				list/ft_42sh_list_fun.c\
				list/ft_42sh_list_in.c\
				list/ft_42sh_list_find.c\
				command/ft_42sh_cm_exit.c\
				command/ft_42sh_cm_echo.c\
				command/ft_42sh_cm_cd.c\
				command/ft_42sh_cm_clear.c\
				command/ft_42sh_cm_env.c\
				command/ft_42sh_cm_setenv.c\
				command/ft_42sh_cm_unsetenv.c\
				parsing/ft_42sh_parsing.c\
				parsing/ft_42sh_parsing_test.c\
				parsing/ft_42sh_parsing_arg.c\
				parsing/ft_42sh_parsing_cmd.c\
				parsing/ft_42sh_parsing_path.c\
				key/ft_42sh_key_litter.c\
				key/ft_42sh_move_caret.c\
				key/ft_42sh_sub_litter.c\
				key/ft_42sh_up_down.c\
				key/ft_42sh_tab.c\
				key/ft_42sh_home_end.c\
				env/ft_42sh_env_start.c\
				env/ft_42sh_env_create.c\
				env/ft_42sh_env_free.c\
				env/ft_42sh_env_parsing.c\
				env/ft_42sh_env_split.c\
				signal/ft_42sh_signal_initilization.c\
				signal/ft_42sh_signal_term.c\
				signal/ft_42sh_signal_int.c\
				signal/ft_42sh_signal_winch.c\
				replase/ft_42sh_replase_cmd.c\
				replase/ft_42sh_replase_arg.c\
				replase/ft_42sh_replase_home.c\
				replase/ft_42sh_replase_slesh.c\
				ft_42sh_init.c\
				ft_42sh_str.c\
				ft_42sh_msg_change.c\
				ft_42sh_init_out.c\
				ft_42sh_read.c\
				ft_42sh_spl_find.c\
				ft_42sh_exit.c

# Все деректории в которых будим искать си файлы для компиляции
DIRS		= src/
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
