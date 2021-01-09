/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:45:06 by wstygg            #+#    #+#             */
/*   Updated: 2021/01/09 13:16:39 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include "conf.h"

static void	file_help(void)
{
	dprintf(fd().o, "Each *.conf file must contain at least one task.\nDefining"
	" a task starts with it's name. Name have to be unique.\nEach task must"
	" contain \"command\" field.\nWhen an error occurs, used default "
	"value.\n\nShort description of all keywords:\n\t"TASK_BOLD"command"
	TASK_RESET"\t\twhat command to use to launch the program.\n\t"TASK_BOLD
	"directory"TASK_RESET"\tdirectory - working directory for task. By "
	"default - current directory.\n\t"TASK_BOLD"umask"TASK_RESET"\t\tumask "
	"for task. By default - 22.\n\t"TASK_BOLD
	"stdout"TASK_RESET"\t\twhere to redirect task's stdout. By default - "
	"1.\n\t"TASK_BOLD"stderr"TASK_RESET"\t\twhere to redirect task's "
	"stderr. By default - 2.\n\t"TASK_BOLD"restart"TASK_RESET"\t\twhether"
	" the program should be restarted always(0), never(1), on unexpected"
	" exits only(2), on good(3). By default - 2.\n\t"TASK_BOLD"retries"TASK_RESET"\t\t"
	"how many times a restart should be attempted before aborting. By "
	"default - 1.\n\t"TASK_BOLD"on_start"TASK_RESET"\twhether to start this"
	" program at launch or not. By default - 1.\n\t"TASK_BOLD"stop_signal"
	TASK_RESET"\twhich signal should be used to stop (i.e. exit gracefully)"
	" the program. By default - 2.\n\t"TASK_BOLD"stop_waiting"TASK_RESET
	"\thow long to wait in seconds after a graceful stop before killing the"
	" program. By default - 5.\n\t"TASK_BOLD"success_waiting"TASK_RESET
	"\thow long the program should be running in seconds after it's started"
	" for it to be considered \"successfully started\". By default - 0.\n"
	"\t"TASK_BOLD"end_codes"TASK_RESET"\twhich return codes represent an "
	"\"expected\" exit status. By default - 0.\n\t"TASK_BOLD"env"TASK_RESET
	"\t\tenvironment variables to set before launching the program.\n");
}

void		conf_help(void)
{
	dprintf(fd().o, "Commands list:\n\t"TASK_BOLD"load [*.conf]"TASK_RESET"\t\t"
	"loads *.conf file, if not specified yet.\n\t"TASK_BOLD"reload"TASK_RESET
	"\t\t\treloads specified *.conf file, to apply new changes.\n\t"TASK_BOLD
	"print"TASK_RESET"\t\t\tprints content of current *.conf file.\n\t"
	TASK_BOLD"help"TASK_RESET"\t\t\ttshows info about 'task' builtin.\n\t"
	TASK_BOLD"delete"TASK_RESET"\t\t\tunloads specified *.conf file and "
	"stops all tasks.\n\t"TASK_BOLD"status"TASK_RESET"\t\t\tshows all current"
	" tasks.\n\t"TASK_BOLD"pause [name] [id]"TASK_RESET"\tif no task "
	"name was given - pausing all task. If several tasks with same name exists"
	" instead pause.\n\t"TASK_BOLD"resume [name] [id]"TASK_RESET"\t"
	"same as 'task pause', but resumes paused tasks.\n\t"TASK_BOLD"run [name] "
	"[id]"TASK_RESET"\t\tsame as 'task resume', but reruns stopped tasks.\n\t"
	TASK_BOLD"restart [name] [id]"TASK_RESET"\tmake a stop to a task, "
	"then run it.\n\n");
	file_help();
}
