/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_jobs.h"

static uintmax_t	fn_pipe(register t_jobs_42sh *last, uintmax_t *count)
{
	register uintmax_t			fd_pipe;
	register uintmax_t			n;

	fd_pipe = 0;
	n = *count & ~(((uintmax_t)1) << (sizeof(uintmax_t) * 8 - 1));
	if (n != *count)
	{
		if (last == 0)
			fd_pipe = PIPE_FIRST_42SH;
		else if (last->fd_pipe != 0)
		{
			n++;
			fd_pipe = PIPE_CENTRAL_42SH;
		}
		n++;
	}
	else if (last != 0 && last->fd_pipe != 0)
	{
		fd_pipe = PIPE_LAST_42SH;
		n++;
	}
	*count = n;
	return (fd_pipe);
}

static void			fn_add_jobs(register t_main_42sh *array,
register t_jobs_42sh *last, register t_jobs_42sh *out)
{
	if (last != 0)
	{
		last->next = out;
		out->prev = last;
	}
	else
		array->pr.jb.first = out;
	array->pr.jb.last = out;
}

t_jobs_42sh			*ft_42sh_jobs_create_add_list(register t_main_42sh *array,
unsigned char *b, register unsigned char *e, size_t n)
{
	uintmax_t					count;
	register t_jobs_42sh		*out;
	register size_t				tempos;
	register uintmax_t			fd_pipe;

	count = ft_42sh_pipe_next_count(array, b, e);
	fd_pipe = fn_pipe(array->pr.jobs_last, &count);
	tempos = sizeof(t_jobs_42sh) + (count * sizeof(t_pipe_42sh));
	if ((out = ft_malloc(tempos)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_memset(out, 0, tempos);
	fn_add_jobs(array, (array->pr.jb.first != 0 ? array->pr.jb.last : 0), out);
	out->n = count;
	out->fd_pipe = fd_pipe;
	array->pr.jobs_last = out;
	ft_42sh_jobs_list_create_id(array, out, n);
	return (out);
}
