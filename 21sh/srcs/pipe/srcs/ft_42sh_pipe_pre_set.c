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

static size_t	fn_open(register t_main_42sh *array,
register t_pipe_42sh *pipe, register unsigned char *dest)
{
	register int			fd;

	if (((fd = pipe->b_flag) & PIPE_LEFT_42SH) != 0)
		fd = O_RDWR;
	else
		fd = O_CREAT | O_RDWR | ((fd & (PIPE_RIGHT2_42SH ^ PIPE_RIGHT_42SH))
		!= 0 ? O_APPEND : O_TRUNC);
	fd = open((char *)dest, fd, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		ft_42sh_dsp_err_msg_add(array, MSG_EXE_DEFINE_42SH, (char *)dest);
		return (0);
	}
	pipe->fd_2 = fd;
	return (1);
}

static size_t	fn_set_add(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in)
{
	register unsigned char			*b;
	register unsigned char			*dest;
	register unsigned char			litter;
	register size_t					count;

	b = *out;
	if ((count = ft_42sh_pipe_pre_heredoc(array, pipe, out, in)) == 0)
		return (1);
	if ((litter = b[0]) == '&')
	{
		b++;
		if (b[0] == '-' && count == 2)
			return (pipe->b_flag |= PIPE_CLOSE_42SH);
		count--;
	}
	if ((dest = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	dest[count] = 0;
	ft_42sh_replase_cmd(array, dest, b, in->end);
	if (litter == '&')
		count = ft_42sh_pipe_pre_number(array, pipe, dest, dest + count);
	else
		count = fn_open(array, pipe, dest);
	ft_free(dest);
	return (count);
}

static void		*fn_set(register t_pipe_42sh *pipe,
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

size_t			ft_42sh_pipe_pre_set(register t_main_42sh *array,
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
	if (fn_set_add(array, pipe, out, in) == 0)
		return (0);
	return (pipe->b_flag);
}
