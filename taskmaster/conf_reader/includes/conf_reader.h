/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:44:57 by wstygg            #+#    #+#             */
/*   Updated: 2021/01/09 12:16:25 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONF_READER_H
# define CONF_READER_H

# include <sys/types.h>
# include <sys/ptrace.h>
# include "errno.h"
# include <unistd.h>
# include <stdio.h>
# include <time.h>

# define TAB_SIZE		4
# define END_CODES_N	255

# define TASK_COL_STATUS					"Status            "
# define TASK_COL_STATUS_TXT_CRITICAL		"Critical          "
# define TASK_COL_STATUS_TXT_FAIL			"Fail              "
# define TASK_COL_STATUS_TXT_STARTING		"Starting          "
# define TASK_COL_STATUS_TXT_RUNING			"Runing            "
# define TASK_COL_STATUS_TXT_STOP			"Pause             "
# define TASK_COL_STATUS_TXT_QUITS			"Quits             "
# define TASK_COL_STATUS_TXT_NOT_ON_START	"N/A               "
# define TASK_COL_STATUS_TXT_COMLETED		"Completed         "
# define TASK_COL_STATUS_TXT_COMLETED_FALED	"Completed Failed  "

# define TASK_COL_STATUS_TXT_PRE_CRITICAL			"Critical: "
# define TASK_COL_STATUS_TXT_PRE_FAIL				"Fail: "
# define TASK_COL_STATUS_TXT_PRE_STARTING			"Starting: "
# define TASK_COL_STATUS_TXT_PRE_RUNING				"Running: "
# define TASK_COL_STATUS_TXT_PRE_STOP				"Pause: "
# define TASK_COL_STATUS_TXT_PRE_QUITS				"Quits: "
# define TASK_COL_STATUS_TXT_PRE_COMLETED			"Completed: "
# define TASK_COL_STATUS_TXT_PRE_COMLETED_FAILED	"Completed Failed: "
# define TASK_COL_STATUS_TXT_PRE_TOTAL				"Total: "

# define TASK_COL_TIME					"Time          "
# define TASK_COL_TIME_TXT				"000.00.00.00  "

# define TASK_COL_RETRIES				"Retries  "
# define TASK_COL_RETRIES_TXT			"000/000  "

# define TASK_COL_PID					"PID         "
# define TASK_COL_PID_TXT				"-1          "

# define TASK_COL_NAME					"Name             "
# define TASK_COL_PATCH					"Path             "

# define TASK_FILE_EXTENSION	".conf"
# define TASK_ERROR_COLOR		"\x1b[31m"
# define TASK_RESET				"\x1b[0m"
# define TASK_BOLD				"\x1b[1m"

# define TASK_BULTIN			"task"

# define TASK_NOT_CMD "\x1b[31m is not a task command.\x1b[0m See 'task help'."
# define TASK_TERMINAL_NOT_SPACE "Not enough display space."
# define TASK_TOO_MANY_ARG		"Too many arguments."
# define TASK_NOT_NAME_JOB		"There are no jobs with this name - "
# define TASK_NOT_ID_JOB		"There are no jobs with this Id - "
# define TASK_FILE_PATH			"Specify the path to the configuration file."
# define TASK_LOAD_RELOAD		" Maybe you wanted to say 'task reload'?"
# define TASK_TASK				" Maybe you wanted to say 'task help'?"
# define TASK_RELOAD_LOAD		" Maybe you wanted to say 'task load'?"
# define TASK_LOAD_ALREDY		"Configuration file already loaded."
# define TASK_REOALD_NOT_LOAD	"Configuration file not yet loaded."
# define TASK_NOT_TASK			"No uploaded tasks."

# define TASK_LOG_EVENT_CORE	"Core"
# define TASK_LOG_SUCCESS		"[Successfully]"
# define TASK_LOG_ERROR			"[Error]"
# define TASK_LOG_CRITICAL		"[Critical]"
# define TASK_LOG_REDIRECT		"Failed redirection"
# define TASK_LOG_MEMORY		"Not enough memory"
# define TASK_LOG_FORK			"Fork failed"

# define TASK_CMD_LOAD			"load"
# define TASK_CMD_RELOAD		"reload"
# define TASK_CMD_PRINT			"print"
# define TASK_CMD_HELP			"help"
# define TASK_CMD_DELETE		"delete"
# define TASK_CMD_STATUS		"status"
# define TASK_CMD_PAUSE			"pause"
# define TASK_CMD_STOP			"stop"
# define TASK_CMD_RESUME		"resume"
# define TASK_CMD_RUN			"run"
# define TASK_CMD_RESTART		"restart"

# define TASK_LOG_DEFAULT_PATH	"/tmp/taskmaster.log"

enum					e_restart
{
	NEVER = 0,
	ALWAYS,
	ON_CRASH,
	ON_GOOD
};

typedef enum			e_status_task
{
	status_task_fail,
	status_task_stop,
	status_task_completed,
	status_task_completed_falled,
	status_task_start,
	status_task_not_auto_start,
	status_task_quits,
	status_task_run
}						t_status_task;

enum					e_params
{
	COMMAND = 0,
	DIRP,
	UMASK,
	COPIES,
	STDOUT,
	STDERR,
	RESTART,
	RETRIES,
	ON_START,
	STOP_SIGNAL,
	STOP_WAITING,
	SUCCESS_WAITING,
	END_CODES,
	ENV,
	PARAMS_N
};

typedef struct			s_fd
{
	int					o;
	int					e;
}						t_fd;

typedef struct			s_jobs
{
	time_t				time_start;
	size_t				time_work;
	int					retries;
	pid_t				pid;
	t_status_task		status_task;
}						t_jobs;

typedef struct			s_task
{
	int					remake;
	char				*name;
	char				*command;
	char				*directory;
	int					umask;
	int					copies;
	char				*tstdout;
	char				*tstderr;
	int					restart;
	int					retries;
	int					on_start;
	int					stop_signal;
	int					stop_waiting;
	int					success_waiting;
	int					end_codes[END_CODES_N];
	char				**env;
	t_jobs				*jobs;
}						t_task;

typedef	struct			s_list
{
	t_task				*task;
	struct s_list		*next;
}						t_list;

typedef struct			s_log
{
	FILE				*fd;
	size_t				size;
	char				*path;
}						t_log;

t_fd					fd(void);
void					set_fd_out(int out);
void					set_fd_err(int err);

void					conf_help(void);
void					task_delete(t_task **task_p);
void					print_tasks(t_list *task_list);
void					task_list_delete(t_list *task_list);
t_list					*conf_read(const char *path);
t_list					*conf_reload(const char *path, t_list *old_tasks);

void					task_log(const char *format, ...);
void					log_reopen(const char *path);

#endif
