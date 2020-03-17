/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static unsigned char	fn_test_fd(register t_main_42sh *array,
register unsigned char *b, register size_t count)
{
	register t_jobs_42sh			*jobs;
	register unsigned char			litter;

	jobs = array->pr.jb.last;
	if (count > 2 || ((litter = b[0] - 0x30) > PIPE_MAX_STANDART_FD_42SH &&
	((jobs->b_fd_left | jobs->b_fd_right) & (1 << litter)) == 0) ||
	((jobs->b_flag_close) & (1 << litter)) != 0)
	{
		ft_42sh_jobs_set_err_n(array, MSG_PIPE_BAD_FD_42SH, b, count);
		return (0xFF);
	}
	return (litter);
}

size_t					ft_42sh_pipe_pre_number(register t_main_42sh *array,
register t_pipe_42sh *pipe, register unsigned char *dest,
register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			litter;
	register size_t					count;

	b = dest;
	pipe->b_flag |= PIPE_AND_42SH;
	while (b < end && (litter = b[0]) >= 0x30 && litter <= 0x39)
		b++;
	b = dest;
	while (b < end && b[0] == 0x30)
		b++;
	if (b == end)
		b--;
	count = end - b;
	if ((litter = fn_test_fd(array, b, count)) == 0xFF)
		return (0);
	pipe->fd_2 = litter;
	return (1);
}
