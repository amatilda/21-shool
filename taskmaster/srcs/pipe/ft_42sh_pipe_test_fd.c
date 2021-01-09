/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_test_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t			ft_42sh_pipe_test_fd(register t_main_42sh *array,
register int fd)
{
	if (fd > FD_MAX_SUPPORT_42SH)
		return (1);
	if ((array->b_fd_close & (1 << fd)) == 0)
		return (0);
	return (1);
}

size_t			ft_42sh_pipe_test_fd_dsp(register t_main_42sh *array,
register int fd, void *name)
{
	register t_write_buff		*err;

	if (ft_42sh_pipe_test_fd(array, fd) == 0)
	{
		array->env.exit_status->number = STATUS_FD_CLOSE_42SH;
		if (ft_42sh_pipe_test_fd(array, STDERR_FILENO) != 0)
		{
			err = &array->err;
			ft_write_buffer(&array->out);
			ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
			ft_write_buffer_str_zero(err, WAR_42SH);
			ft_write_buffer_str_zero(err, name);
			ft_write_buffer_str_zero(err, MSG_PIPE_BAD_FD_42SH""PRTF_RESET);
			ft_write_buffer_char(err, (fd + 0x30), 1);
			ft_write_buffer_str_zero(err, "\n");
			ft_write_buffer(err);
		}
		return (0);
	}
	return (1);
}
