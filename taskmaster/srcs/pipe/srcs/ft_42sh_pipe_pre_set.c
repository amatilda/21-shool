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
	if (ft_42sh_pipe_pre_set_add(array, pipe, out, in) == 0)
		return (0);
	return (pipe->b_flag);
}
