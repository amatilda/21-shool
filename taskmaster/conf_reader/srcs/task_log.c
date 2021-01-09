/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:22:05 by wstygg            #+#    #+#             */
/*   Updated: 2021/01/09 13:44:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"
#include "conf_reader.h"

#include <time.h>

void			log_reopen(const char *path)
{
	t_log		*log;

	log = get_log();
	if (log->fd)
		fclose(log->fd);
	log->fd = fopen(path, "a+");
	if (log->fd)
	{
		fseek(log->fd, 0L, SEEK_END);
		log->size = ftell(log->fd);
		free(log->path);
		log->path = strdup(path);
	}

}

static void		log_recreate(void)
{
	fclose(get_log()->fd);
	remove(get_log()->path);
	log_reopen(get_log()->path);
}

void			task_log(const char *format, ...)
{
	va_list		list;
	time_t		t;
	struct tm	tm;

	if (get_log()->size >= MAX_LOG_SIZE)
		log_recreate();
	if (get_log()->fd)
	{
		va_start(list, format);
		t = time(NULL);
		tm = *localtime(&t);
		get_log()->size += fprintf(get_log()->fd,
				"[%02d-%02d-%d\t%02d:%02d:%02d]\n",
				tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
				tm.tm_hour, tm.tm_min, tm.tm_sec);
		get_log()->size += vfprintf(get_log()->fd, format, list);
		get_log()->size += fprintf(get_log()->fd, "\n\n");
		va_end(list);
	}
}
