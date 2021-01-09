/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_task_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:41:42 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 14:58:02 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

int				check_task_name(const char *name, t_list *tasks, const int i)
{
	t_task		*task;
	t_list		*lst;

	lst = tasks;
	while (lst)
	{
		task = lst->task;
		if (!strcmp(task->name, name))
		{
			ft_error("Task name in [%d] line is have to be unique - %s!",
					i + 1, name);
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}
