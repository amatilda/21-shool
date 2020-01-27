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

void		ft_42sh_dsp_err_msg(register t_main_42sh *array,
register char *str)
{
	register t_write_buff		*err;

	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, str);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
}

void		ft_42sh_dsp_err_msg_add(register t_main_42sh *array,
register void *str, register char *add)
{
	register t_write_buff		*err;

	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, str);
	ft_write_buffer_str_zero(err, add);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
}

void		ft_42sh_dsp_err_msg_add_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n)
{
	register t_write_buff		*err;

	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, str);
	ft_write_buffer_str(err, add, n);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
}
