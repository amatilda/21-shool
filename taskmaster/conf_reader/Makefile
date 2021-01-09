NAME		= conf_reader.a
DIRS		= srcs/
LIST		=	check_file.c\
				check_uniq.c\
				conf_help.c\
				conf_reload.c\
				conf.c\
				create_2.c\
				create_3.c\
				create_env.c\
				create_job.c\
				create.c\
				ft_2.c\
				ft_splitstr.c\
				ft.c\
				get_nl.c\
				list_2.c\
				list.c\
				str.c\
				fd.c\
				fill_task.c\
				open_conf.c\
				check_task_name.c\
				task_log.c\
				get_log_fd.c\
				print_tasks.c\
				task_delete.c

SOURCE		= $(addprefix $(DIRS), $(LIST))
OBJ			= $(patsubst %.c,%.o,$(SOURCE))
D_FILE		= $(patsubst %.c,%.d,$(SOURCE))
INCLUDES	= includes/

override OPFLAGS ?= -O2
override FLAGS ?= -Wall -Wextra -Werror 

all:
	@make -j $(NAME)

debug:
	@make OPFLAGS="-O0 -g"

test:
	@make FLAGS=""

%.o: %.c
	@gcc $(FLAGS) $(OPFLAGS) -I$(INCLUDES) -c $< -o $@ -MD

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
