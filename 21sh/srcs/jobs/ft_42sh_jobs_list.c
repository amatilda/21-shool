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

#include "ft_42sh.h"

static uintmax_t	fn_pipe(register t_jobs_42sh *last,
uintmax_t *count)
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

static char			*fn_strjoin(register char const *s1,
register char const *s2)
{
	register char	*out;
	register size_t	count;
	register size_t	size;

	size = 0;
	while (s1[size] != 0)
		size++;
	count = 0;
	while (s2[count] != 0)
		count++;
	size += count;
	if ((out = malloc(size + 2)) == 0)
		return (0);
	size = (size_t)out;
	while ((count = (unsigned char)s1++[0]) != 0)
		out++[0] = (unsigned char)count;
	out++[0] = '/';
	while ((count = (unsigned char)s2++[0]) != 0)
		out++[0] = (unsigned char)count;
	out[0] = 0;
	return ((char *)size);
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

static void			fn_set_exe(register t_jobs_42sh *out,
register t_all_cmd_42sh **spl)
{
	register size_t				b_type;
	register void				*path;

	if (spl != 0)
	{
		if ((b_type = spl[0]->b_type) == AUTO_TYPE_EXE)
		{
			if ((path = fn_strjoin(spl[0]->path, spl[0]->std.lp_key)) == 0)
				ft_42sh_exit(E_MEM_CODE_42SH);
		}
		else
			path = spl[0]->path;
	}
	else
	{
		b_type = AUTO_TYPE_EXE;
		path = 0;
	}
	out->b_type = b_type;
	out->path = path;
}

t_jobs_42sh			*ft_42sh_jobs_create_add_list(register t_main_42sh *array,
register char **lp_arg, register t_all_cmd_42sh **spl, uintmax_t count)
{
	register t_jobs_42sh		*out;
	register t_jobs_42sh		*last;
	register size_t				tempos;
	register uintmax_t			fd_pipe;

	last = array->pr.jb.first != 0 ? array->pr.jb.last : 0;
	fd_pipe = fn_pipe(last, &count);
	tempos = sizeof(t_jobs_42sh) + (count * sizeof(t_pipe_42sh));
	if ((out = ft_malloc(tempos)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memset(out, 0, tempos);
	fn_add_jobs(array, last, out);
	fn_set_exe(out, spl);
	out->lp_arg = lp_arg;
	out->n = count;
	out->fd_pipe = fd_pipe;
	return (out);
}
