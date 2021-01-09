/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_thread_lock.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			ft_42sh_task_thread_share(register t_main_42sh *array)
{
	size_t				count_read;

	while (0xFF)
	{
		pthread_mutex_lock(&array->task.mutex);
		if ((count_read = array->task.count_read) != (size_t)(-1))
			array->task.count_read++;
		pthread_mutex_unlock(&array->task.mutex);
		if (count_read != (size_t)(-1))
			break ;
		usleep(400000);
	}
}

void			ft_42sh_task_thread_excluze(register t_main_42sh *array)
{
	size_t				count_read;

	while (0xFF)
	{
		pthread_mutex_lock(&array->task.mutex);
		if ((count_read = array->task.count_read) == 0)
			array->task.count_read = (size_t)(-1);
		pthread_mutex_unlock(&array->task.mutex);
		if (count_read == 0)
			break ;
		usleep(400000);
	}
}

void			ft_42sh_task_thread_unshare(register t_main_42sh *array)
{
	pthread_mutex_lock(&array->task.mutex);
	array->task.count_read--;
	pthread_mutex_unlock(&array->task.mutex);
}

void			ft_42sh_task_thread_unexcluze(register t_main_42sh *array)
{
	pthread_mutex_lock(&array->task.mutex);
	array->task.count_read = 0;
	pthread_mutex_unlock(&array->task.mutex);
}
