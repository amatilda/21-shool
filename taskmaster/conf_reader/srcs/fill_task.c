/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_task.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:20:17 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:29:06 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static void		fill_task_next_next(char **conf, int *i, t_task *task,
										int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (!strncmp(str, "stop_waiting: ", 14))
		check_uniq(STOP_WAITING, uniq, *i, conf[*i]) ?
		(task->stop_waiting = create_stop_waiting(conf[*i], *i)) : 0;
	else if (!strncmp(str, "success_waiting: ", 17))
		check_uniq(SUCCESS_WAITING, uniq, *i, conf[*i]) ?
		(task->success_waiting = create_success_waiting(conf[*i], *i)) : 0;
	else if (!strncmp(str, "end_codes: ", 11))
		check_uniq(END_CODES, uniq, *i, conf[*i]) ?
		(create_end_codes(task->end_codes, conf[*i], *i)) : 0;
	else if (!strncmp(str, "env:", 4))
		check_uniq(ENV, uniq, *i, conf[*i]) ? (create_env(task, conf, i)) : 0;
	else
		ft_error("Error at [%d] line: %s\nUnknown keyword!\n",
					*i + 1, conf[*i]);
}

static void		fill_task_next(char **conf, int *i, t_task *task,
								int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (!strncmp(str, "stdout: ", 8))
		check_uniq(STDOUT, uniq, *i, conf[*i]) ?
		(task->tstdout = create_stdout(conf[*i], *i, task->tstdout)) : 0;
	else if (!strncmp(str, "stderr: ", 8))
		check_uniq(STDERR, uniq, *i, conf[*i]) ?
		(task->tstderr = create_stderr(conf[*i], *i, task->tstderr)) : 0;
	else if (!strncmp(str, "restart: ", 9))
		check_uniq(RESTART, uniq, *i, conf[*i]) ?
		(task->restart = create_restart(conf[*i], *i)) : 0;
	else if (!strncmp(str, "retries: ", 9))
		check_uniq(RETRIES, uniq, *i, conf[*i]) ?
		(task->retries = create_retries(conf[*i], *i)) : 0;
	else if (!strncmp(str, "on_start: ", 10))
		check_uniq(ON_START, uniq, *i, conf[*i]) ?
		(task->on_start = create_on_start(conf[*i], *i)) : 0;
	else if (!strncmp(str, "stop_signal: ", 13))
		check_uniq(STOP_SIGNAL, uniq, *i, conf[*i]) ?
		(task->stop_signal = create_stop_signal(conf[*i], *i)) : 0;
	else
		fill_task_next_next(conf, i, task, uniq);
}

void			fill_task(char **conf, int *i, t_task *task,
						int uniq[PARAMS_N])
{
	char		*str;

	str = skip_emptiness(conf[*i]);
	if (tab_count(conf[*i]) != 1)
		ft_error("Error at [%d] line:\n%s\nThere have to be 1 tab depth before "
					"keyword!\n", *i + 1, conf[*i]);
	else if (!strchr(str, ':'))
		ft_error("Error at [%d] line: %s\nKeyword have to followed by ':' "
					"symbol!\n", *i + 1, conf[*i]);
	else if (!strncmp(str, "command: ", 9))
		check_uniq(COMMAND, uniq, *i, conf[*i]) ?
		(task->command = create_command(conf[*i], *i)) : 0;
	else if (!strncmp(str, "directory: ", 11))
		check_uniq(DIRP, uniq, *i, conf[*i]) ?
		(task->directory = create_directory(conf[*i], *i, task->directory)) : 0;
	else if (!strncmp(str, "umask: ", 7))
		check_uniq(UMASK, uniq, *i, conf[*i]) ?
		(task->umask = create_umask(conf[*i], *i)) : 0;
	else if (!strncmp(str, "copies: ", 8))
		check_uniq(COPIES, uniq, *i, conf[*i]) ?
		(task->copies = create_copies(conf[*i], *i)) : 0;
	else
		fill_task_next(conf, i, task, uniq);
}
