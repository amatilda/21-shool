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
	while (0xFF)
	{
		ft_42sh_replase_arg_count(array, out, end, 0);
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

size_t				ft_42sh_pipe_pre(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **out, register unsigned char *end)
{
	register t_pipe_42sh			*pipe;
	register unsigned char			*b;
	register size_t					litter;
	t_pipe_in_42sh					in;

	in.list = list;
	if ((pipe = fn_set_pre(array, array->pr.jb.last, end, &in)) == 0)
		return (1);
	while ((b = *out) < end && ft_42sh_parsing_litter_e(b[0]) != 0)
	{
		if (ft_42sh_parsing_test_pipe(b, end, b[0], 0x20) == 0)
			b = fn_while_arg(array, b, out, end);
		else
		{
			if ((litter = ft_42sh_pipe_pre_set(array, pipe, out, &in)) == 0)
				return (0);
			else if (litter == PIPE_42SH)
				break ;
			if (ft_42sh_pipe_pre_finish(array, array->pr.jb.last,
			pipe, pipe->b_flag) == 0)
				return (0);
			pipe++;
		}
	}
	return (1);
}
