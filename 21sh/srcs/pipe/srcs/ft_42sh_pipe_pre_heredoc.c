/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_heredoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static void			*fn_end(register t_main_42sh *array, unsigned char *out,
register unsigned char *e, register size_t tempos)
{
	if (tempos != 0)
	{
		if (array->dq.hrdoc_start_lp == 0)
			array->dq.hrdoc_start_lp = array->dq.hrdoc_next_lp;
		return (array->dq.hrdoc_next_lp);
	}
	while (out < e && out[0] != '\n')
	{
		ft_42sh_parsing_end(array, &out, e, 0);
		if (out[0] == ';')
			out++;
	}
	out++;
	if (array->dq.hrdoc_start_lp == 0)
		array->dq.hrdoc_start_lp = out;
	return (out);
}

static t_slesh_42sh	**fn_spl(t_pipe_in_42sh *in, register char *end,
register size_t tempos)
{
	register size_t					count;
	register t_slesh_42sh			**spl;
	register t_slesh_42sh			**spl_end;
	register t_in_42sh				*list;

	list = in->list;
	spl = &list->spl_slesh[tempos];
	if (tempos != 0)
		return (spl);
	count = end - list->lp_b;
	spl_end = &spl[list->slesh_max];
	while ((tempos += spl[0]->count + 2) <= count)
		spl++;
	return (spl);
}

static size_t		fn_finish(register t_main_42sh *array,
register void *cmp)
{
	array->dq.hrdoc_last_lp = array->dq.hrdoc_next_lp;
	ft_free(cmp);
	return (0);
}

size_t				ft_42sh_pipe_pre_heredoc(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in)
{
	register void					*cmp;
	register t_slesh_42sh			**spl;
	register size_t					count;
	register size_t					tempos;
	register void					*b;

	b = *out;
	count = ft_42sh_replase_cmd_count(array, out, in->end, 0);
	if ((pipe->b_flag & PIPE_LEFT2_42SH) != PIPE_LEFT2_42SH)
		return (count);
	if ((cmp = ft_malloc(count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_replase_cmd(array, cmp, b, in->end);
	tempos = array->dq.hrdoc_next_slesh;
	b = fn_end(array, array->dq.hrdoc_next_lp, in->end, tempos);
	pipe->lp_heredok_b = b;
	spl = fn_spl(in, b, tempos);
	pipe->lp_heredok_spl = spl;
	while ((tempos = spl++[0]->count) != count ||
	ft_strncmp(b, cmp, count) != 0)
		b += tempos + 2;
	array->dq.hrdoc_next_lp = b + tempos + 2;
	array->dq.hrdoc_next_slesh = spl - in->list->spl_slesh;
	pipe->lp_heredok_spl_end = spl - 1;
	return (fn_finish(array, cmp));
}
