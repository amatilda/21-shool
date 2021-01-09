/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_set_add.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static size_t			fn_set_add_ret(register t_pipe_42sh *pipe,
unsigned char **out, register unsigned char *b)
{
	*out = b + 1;
	return (pipe->b_flag |= PIPE_CLOSE_42SH);
}

static size_t			fn_set_add_count(register t_main_42sh *array,
t_replase_in_42sh *rpl, unsigned char **out, t_pipe_in_42sh *in)
{
	unsigned char					*start;
	register size_t					count;

	rpl->array = array;
	rpl->b_mode = PARSING_MODE_ARG_42SH;
	start = *out;
	count = ft_42sh_replase_count(rpl, &start, out, in->end);
	return (count);
}

static size_t			fn_test_litter(t_pipe_in_42sh *in,
register unsigned char *b, register unsigned char litter)
{
	if (litter == '&' && (litter = b[0]) >= 0x30 && litter <= 0x39 &&
	(ft_42sh_parsing_litter_e_f(b + 1, in->end) == 0 || b[1] == 0x20))
	{
		return (1);
	}
	return (0);
}

static void				*fn_replase(t_replase_in_42sh *rpl,
t_pipe_in_42sh *in, register unsigned char *b,
register size_t count)
{
	register unsigned char			*dest;

	if ((dest = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	dest[count] = 0;
	ft_42sh_replase(rpl, dest, b, in->end);
	return (dest);
}

size_t					ft_42sh_pipe_pre_set_add(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in)
{
	register unsigned char			*b;
	register unsigned char			*dest;
	register unsigned char			litter;
	register size_t					count;
	t_replase_in_42sh				rpl;

	if ((count = ft_42sh_pipe_pre_heredoc(array, pipe, out, in)) == 0)
		return (1);
	if (count == PARSING_FALTURE_42SH)
		return (0);
	b = *out;
	if ((litter = b[0]) == '&')
		if (b++[1] == '-')
			return (fn_set_add_ret(pipe, out, b));
	*out = b;
	count = fn_set_add_count(array, &rpl, out, in);
	if (array->pr.exit_pars.lp != 0)
		return (0);
	dest = fn_replase(&rpl, in, b, count);
	if (fn_test_litter(in, b, litter) != 0)
		count = ft_42sh_pipe_pre_number(array, pipe, dest, dest + count);
	else
		count = ft_42sh_pipe_pre_set_open(array, pipe, dest);
	ft_free(dest);
	return (count);
}
