/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_pipe.h"

static void			*fn_while_arg(register t_main_42sh *array,
register unsigned char *b, unsigned char **out, register unsigned char *end)
{
	t_replase_in_42sh		in;
	unsigned char			*start;

	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH;
	while (0xFF)
	{
		start = *out;
		ft_42sh_replase_count(&in, &start, out, end);
		if (*out == b)
			break ;
		b = *out;
	}
	return (b);
}

static t_pipe_42sh	*fn_set_pre(register t_main_42sh *array,
register t_jobs_42sh *jobs, register unsigned char *end,
register t_pipe_in_42sh *in)
{
	if (jobs->n == 0)
		return (0);
	array->dq.hrdoc_next_slesh = 0;
	in->end = end;
	return (ft_42sh_pipe_pre_pipe(jobs, &jobs->pipe[0]));
}

static size_t		fn_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_pipe_42sh *pipe)
{
	if (ft_42sh_pipe_pre_and_right(jobs, &jobs->pipe[0], pipe) == 0)
	{
		ft_42sh_jobs_set_err(array, MSG_PIPE_LIMIT_FD_42SH,
		"", STATUS_FALTURE_42SH);
		return (0);
	}
	return (1);
}

size_t				ft_42sh_pipe_pre(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *out, register unsigned char *end)
{
	register t_pipe_42sh			*pipe;
	register unsigned char			*b;
	t_pipe_in_42sh					in;

	in.list = list;
	if ((pipe = fn_set_pre(array, array->pr.jb.last, end, &in)) == 0)
		return (1);
	while ((b = out) < end && ft_42sh_parsing_litter_e(b, end) != 0)
	{
		if (ft_42sh_parsing_test_pipe(b, end, 0x20) == 0)
			b = fn_while_arg(array, b, &out, end);
		else
		{
			array->sh.lp_cmd = out;
			if ((in.litter = ft_42sh_pipe_pre_set(array, pipe, &out, &in)) == 0)
				return (0);
			else if (in.litter == PIPE_42SH)
				break ;
			if (ft_42sh_pipe_pre_finish(array, array->pr.jb.last,
			pipe, pipe->b_flag) == 0)
				return (0);
			pipe++;
		}
	}
	return (fn_finish(array, array->pr.jb.last, pipe));
}
