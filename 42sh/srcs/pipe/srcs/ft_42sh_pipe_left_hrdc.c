/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_left_hrdc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static void	fn_dq(register t_main_42sh *array, register unsigned char *b,
register unsigned char *e, register int fd_write)
{
	register unsigned char			*tmp;

	array->out.fd = fd_write;
	array->out.count = 0;
	tmp = b;
	while (b < e)
	{
		if (b++[0] == 0x20 && b < e && b[0] == '\n')
		{
			ft_write_buffer_str(&array->out, (void *)tmp, b - tmp - 1);
			tmp = b;
		}
	}
	ft_write_buffer_str(&array->out, (void *)tmp, b - tmp);
	if (b[-1] != '\n')
		ft_write_buffer_str_zero(&array->out, "\n");
	ft_write_buffer(&array->out);
}

void		ft_42sh_pipe_left_hrdc(register t_main_42sh *array,
register t_pipe_42sh *pipe, register int fd_write)
{
	register unsigned char			*b;
	register unsigned char			*e;
	register size_t					tempos;

	if (((tempos = pipe->b_heredok) & JOBS_HRDC_EMPTY_42SH) != 0)
		return ;
	b = pipe->lp_heredok_b;
	e = pipe->lp_heredok_e;
	if ((tempos & JOBS_HRDC_42SH) != 0)
	{
		write(fd_write, b, (size_t)e);
		return ;
	}
	if ((tempos & JOBS_HRDC_DQ_42SH) != 0)
		return (fn_dq(array, b, e, fd_write));
	ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
}
