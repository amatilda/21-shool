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

static void				fn_test(register t_pipe_42sh *pipe,
register unsigned char *b, register unsigned char *e)
{
	register unsigned char		litter;

	while (b < e)
	{
		if ((litter = b++[0]) == '\'' || litter == '"')
		{
			pipe->lp_heredok_e = (void *)1;
			return ;
		}
	}
	pipe->lp_heredok_e = 0;
}

static void				*fn_test_empty(register
t_main_42sh *array, register t_pipe_42sh *pipe,
t_pipe_in_42sh *in, register size_t tempos)
{
	register unsigned char			*b;

	if ((b = ft_42sh_pipe_pre_heredoc_end(array, array->dq.hrdoc_next_lp,
	in->end, tempos)) == in->end)
	{
		pipe->b_heredok = JOBS_HRDC_EMPTY_42SH;
		return (0);
	}
	pipe->lp_heredok_b = b;
	return (b);
}

static void				fn_finish(register
t_main_42sh *array, register size_t index,
register unsigned char *b, register unsigned char *cmp)
{
	array->dq.hrdoc_next_lp = b;
	array->dq.hrdoc_next_slesh = index;
	ft_free(cmp);
}

static void				*fn_while(register t_slesh_42sh **spl,
register size_t tempos, register unsigned char *b)
{
	b += tempos + 2;
	return (b);
	(void)spl;
}

size_t					ft_42sh_pipe_pre_heredoc(register
t_main_42sh *array, register t_pipe_42sh *pipe,
unsigned char **out, t_pipe_in_42sh *in)
{
	register unsigned char			*cmp;
	register t_slesh_42sh			**spl;
	register size_t					count;
	register size_t					tempos;
	register unsigned char			*b;

	b = *out;
	if ((pipe->b_flag & PIPE_LEFT2_42SH) != PIPE_LEFT2_42SH)
		return (1);
	count = ft_42sh_replase_hrdc_name_count(array, out, in->end);
	fn_test(pipe, b, *out);
	if ((cmp = ft_malloc(count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_42sh_replase_hrdc_name(array, cmp, b, in->end);
	tempos = array->dq.hrdoc_next_slesh;
	if ((b = fn_test_empty(array, pipe, in, tempos)) == 0)
		return (0);
	spl = ft_42sh_pipe_pre_heredoc_spl(in, (char *)b, tempos);
	while (spl[0] != 0 && ((tempos = spl[0]->count) != count ||
	ft_strncmp((char *)b, (char *)cmp, count) != 0))
		b = fn_while(spl++, tempos, b);
	fn_finish(array, (spl - in->list->spl_slesh) + 1, b + tempos + 2, cmp);
	return (ft_42sh_pipe_pre_heredoc_set(array, pipe, spl, b));
}
