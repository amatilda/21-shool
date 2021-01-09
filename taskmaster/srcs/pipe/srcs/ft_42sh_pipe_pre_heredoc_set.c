/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_heredoc_set.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static void		*fn_skip(register unsigned char *b,
register unsigned char *e)
{
	while (b < e)
	{
		b = ft_42sh_parsing_sp(b, e);
		if (ft_42sh_parsing_litter_e(b, e) != 0)
			return (b);
		b++;
	}
	return (b);
}

void			*ft_42sh_pipe_pre_heredoc_end(register t_main_42sh *array,
unsigned char *out, register unsigned char *e,
register size_t tempos)
{
	if (tempos != 0)
		return (array->dq.hrdoc_next_lp);
	out = fn_skip(out, e);
	while (out < e && out[0] != '\n')
	{
		ft_42sh_parsing_end(array, &out, e, ft_42sh_parsing_litter_e);
		if (out < e && out[0] != '\n')
			out = ft_42sh_parsing_litter_e_l(out, e);
	}
	out++;
	if (out > e)
		return (e);
	return (out);
}

t_slesh_42sh	**ft_42sh_pipe_pre_heredoc_spl(t_pipe_in_42sh *in,
register char *end, register size_t tempos)
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

size_t			ft_42sh_pipe_pre_heredoc_set(register t_main_42sh *array,
register t_pipe_42sh *pipe, register t_slesh_42sh **spl,
register unsigned char *e)
{
	register size_t				count;
	register unsigned char		*dest;
	register unsigned char		*b;

	e -= ((spl[0] == 0) ? 2 : 0);
	if (pipe->lp_heredok_e != 0)
	{
		pipe->b_heredok = JOBS_HRDC_DQ_42SH;
		pipe->lp_heredok_e = e;
		return (0);
	}
	b = pipe->lp_heredok_b;
	count = ft_42sh_replase_hrdc_count(array, b, e);
	if (array->pr.exit_pars.lp != 0)
		return (PARSING_FALTURE_42SH);
	if ((dest = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_42sh_replase_hrdc(array, dest, b, e);
	if (count != 0 && spl[0] == 0 && spl[-1]->count != 0)
		dest[count++] = '\n';
	pipe->b_heredok = JOBS_HRDC_42SH;
	pipe->lp_heredok_b = dest;
	pipe->lp_heredok_e = (void *)count;
	return (0);
}
