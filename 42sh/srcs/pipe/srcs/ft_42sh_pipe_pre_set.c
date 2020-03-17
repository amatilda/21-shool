/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_set.c                             :+:      :+:    :+:   */
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

static size_t			fn_set_add(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in)
{
	register unsigned char			*b;
	register unsigned char			*dest;
	register unsigned char			litter;
	register size_t					count;
	t_replase_in_42sh				rpl;

	if ((count = ft_42sh_pipe_pre_heredoc(array, pipe, out, in)) == 0)
		return (1);
	b = *out;
	if ((litter = b[0]) == '&')
		if (b++[1] == '-')
			return (fn_set_add_ret(pipe, out, b));
	*out = b;
	count = fn_set_add_count(array, &rpl, out, in);
	if (array->pr.exit_pars.lp != 0)
		return (0);
	if ((dest = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	dest[count] = 0;
	ft_42sh_replase(&rpl, dest, b, in->end);
	if (litter == '&' && (litter = b[0]) >= 0x30 && litter <= 0x39)
		count = ft_42sh_pipe_pre_number(array, pipe, dest, dest + count);
	else
		count = ft_42sh_pipe_pre_set_open(array, pipe, dest);
	ft_free(dest);
	return (count);
}

static void				*fn_set(register t_pipe_42sh *pipe,
register unsigned char *b, register unsigned char fd,
register unsigned char litter)
{
	if ((litter = b++[0]) == '&')
	{
		litter = b++[0];
		pipe->b_flag |= PIPE_ADD_ERR_42SH;
	}
	if (litter == '>')
	{
		fd = (fd >= 0x30 && fd <= 0x39) ? fd - 0x30 : 1;
		pipe->b_flag |= PIPE_RIGHT_42SH;
	}
	else
	{
		fd = (fd >= 0x30 && fd <= 0x39) ? fd - 0x30 : 0;
		pipe->b_flag |= PIPE_LEFT_42SH;
	}
	pipe->fd_1 = fd;
	if (litter == b[0])
	{
		b++;
		pipe->b_flag |= (litter == '>') ? PIPE_RIGHT2_42SH : PIPE_LEFT2_42SH;
	}
	return (b);
}

size_t					ft_42sh_pipe_pre_set(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in)
{
	register unsigned char			*b;
	register unsigned char			litter;
	register unsigned char			fd;

	b = *out;
	if ((litter = b[0]) == '|')
	{
		*out = *out + 1;
		return (PIPE_42SH);
	}
	if ((fd = litter) >= 0x30 && fd <= 0x39)
		b++;
	*out = fn_set(pipe, b, fd, litter);
	if ((pipe->b_flag & PIPE_LEFT_42SH) != 0 &&
	(((t_jobs_42sh *)array->pr.jb.last)->b_flag_close &
	(1 << pipe->fd_1)) != 0)
	{
		ft_42sh_jobs_set_err_n(array, MSG_PIPE_MUL_FD_42SH, b - 1, 1);
		return (0);
	}
	if (fn_set_add(array, pipe, out, in) == 0)
		return (0);
	return (pipe->b_flag);
}
