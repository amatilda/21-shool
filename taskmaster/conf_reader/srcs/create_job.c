/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:40:09 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:28:04 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static void			check_task(t_task **task_p)
{
	t_task			task;

	task = **task_p;
	if (!task.command)
	{
		ft_error("%s task is incomplete. Missing \"command\" "
				"field!\n", task.name);
		task_delete(task_p);
	}
}

static void			task_init(t_task **task)
{
	register int	k;

	*task = my_malloc(sizeof(t_task));
	**task = (t_task)
	{
		.remake = 1, .umask = 22, .copies = 1, .restart = 2, .retries = 1,
		.on_start = 1, .stop_signal = 2, .stop_waiting = 5,
		.success_waiting = 0, .end_codes[0] = 0
	};
	if (!((*task)->directory = getcwd(NULL, 80)))
		ft_crash("getcwd malloc error!");
	(*task)->tstdout = 0;
	(*task)->tstderr = 0;
	k = 0;
	while (++k < END_CODES_N)
		(*task)->end_codes[k] = -1;
}

t_task				*create_task(char **conf, int *i, t_list *tasks)
{
	register int	k;
	t_task			*task;
	int				params_uniq[PARAMS_N];

	k = -1;
	while (++k < PARAMS_N)
		params_uniq[k] = 0;
	task_init(&task);
	if (!(task->name = create_name(conf[*i], *i)) ||
		!check_task_name(task->name, tasks, *i))
	{
		task_delete(&task);
		return (NULL);
	}
	while (conf[++(*i)])
	{
		if (str_is_empty(conf[*i]))
			continue ;
		if (tab_count(conf[*i]) == 0)
			break ;
		fill_task(conf, i, task, params_uniq);
	}
	check_task(&task);
	(*i)--;
	return (task);
}
