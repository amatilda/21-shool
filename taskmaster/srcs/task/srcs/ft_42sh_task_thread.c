/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

size_t			ft_42sh_task_thread_init(register t_main_42sh *array)
{
	pthread_mutex_init(&array->task.mutex, NULL);
	array->task.count_read = 0;
	pthread_create(&array->task.thread, NULL,
	(void *(*)(void *))ft_42sh_task_thread, array);
	return (0);
}

void			ft_42sh_task_thread_deinit(register t_main_42sh *array)
{
	pthread_mutex_lock(&array->task.mutex);
	pthread_cancel(array->task.thread);
	pthread_mutex_unlock(&array->task.mutex);
	pthread_mutex_destroy(&array->task.mutex);
}

void			ft_42sh_task_thread(register t_main_42sh *array)
{
	size_t							b_cmd;
	char							*lp_arg[2];

	lp_arg[1] = 0;
	while (0xFF)
	{
		pthread_mutex_lock(&array->task.mutex);
		ft_42sh_task_upd_status(array);
		ft_42sh_task_auto(array);
		b_cmd = 0;
		if (array->task.b_reload == 1 && array->task.b_cmd == 0)
			b_cmd = 1;
		pthread_mutex_unlock(&array->task.mutex);
		if (b_cmd == 1)
		{
			ft_42sh_task_cmd_reload(array, &lp_arg[0]);
			ft_42sh_dsp_start(array);
			ft_write_buffer(&array->out);
			array->task.b_reload = 0;
		}
		sleep(1);
	}
}
