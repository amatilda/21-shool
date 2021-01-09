/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:53:44 by wstygg            #+#    #+#             */
/*   Updated: 2020/08/04 17:58:43 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"
#include "conf_reader.h"

static const char	*outhelper(const char *out)
{
	if (out == NULL)
		return ("*stdout*");
	else if (out == (char*)1)
		return ("*stderr*");
	else
		return (out);
}

static const char	*errhelper(const char *err)
{
	if (err == NULL)
		return ("*stderr*");
	else if (err == (char*)1)
		return ("*stdout*");
	else
		return (err);
}

void				print_tasks(t_list *tasks)
{
	int				count;
	t_task			*task;
	register int	i;

	count = 1;
	while (tasks && (i = -1))
	{
		task = tasks->task;
		dprintf(fd().o, "Job #%i:\nName - %s\nCommand - %s\nDirectory - %s\n"
		"Umask - %d\nCopies - %d\nStdout - %s\nStderr - %s\nRestart - %d\n"
		"Retries - %d\nOn_start - %d\nStop_signal - %d\nStop_waiting - %d\n"
		"Success_waiting - %d\nEnd_codes: ", count++, task->name, task->command,
		task->directory, task->umask, task->copies, outhelper(task->tstdout),
		errhelper(task->tstderr), task->restart, task->retries, task->on_start,
		task->stop_signal, task->stop_waiting, task->success_waiting);
		while (task->end_codes[++i] != -1 && i < END_CODES_N)
			dprintf(fd().o, "%i%c", task->end_codes[i],
					(task->end_codes[i + 1] != -1) ? ' ' : '\n');
		(task->env) ? dprintf(fd().o, "Env:\n") : 0;
		if (task->env && (i = -1))
			while (task->env[++i])
				dprintf(fd().o, "    %s\n", task->env[i]);
		tasks = tasks->next;
		dprintf(fd().o, "\n");
	}
}
