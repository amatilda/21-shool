/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_dsp_err_msg_adds(register t_main_42sh *array,
register char *str, register void *add, register void *adds)
{
	register t_write_buff		*err;

	array->env.exit_status->number = STATUS_FALTURE_42SH;
	if (ft_42sh_pipe_test_fd(array, STDERR_FILENO) == 0)
		return ;
	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, str);
	ft_write_buffer_str_zero(err, add);
	ft_write_buffer_str_zero(err, adds);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
}

void		ft_42sh_dsp_err_msg(register t_main_42sh *array,
register char *str)
{
	register t_write_buff		*err;

	array->env.exit_status->number = STATUS_FALTURE_42SH;
	if (ft_42sh_pipe_test_fd(array, STDERR_FILENO) == 0)
		return ;
	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, str);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
}

void		ft_42sh_dsp_err_msg_add_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n)
{
	register t_write_buff		*err;

	array->env.exit_status->number = STATUS_FALTURE_42SH;
	if (ft_42sh_pipe_test_fd(array, STDERR_FILENO) == 0)
		return ;
	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, str);
	if (n == 0)
		ft_write_buffer_str_zero(err, add);
	else
		ft_write_buffer_str(err, add, n);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
}
