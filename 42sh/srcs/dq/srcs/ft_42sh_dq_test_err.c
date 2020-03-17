/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_err.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static void		fn_script(register t_main_42sh *array,
register t_write_buff *err, register unsigned char *add)
{
	register unsigned char			*b;
	register size_t					count;
	char							buff[sizeof(size_t) * 3 + 1 + 1];

	b = (void *)array->in.in_current->lp_b;
	count = 1;
	while (b < add)
		if (b++[0] == '\n')
			count++;
	buff[0] = ':';
	count = ft_itoa(buff + 1, count, 10, ITOA_LOWER);
	buff[count + 1] = 0;
	ft_write_buffer_str_zero(err, (void *)array->sh.path);
	ft_write_buffer_str_zero(err, buff);
}

unsigned char	ft_42sh_dq_test_err_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n)
{
	register t_write_buff		*err;

	if ((array->b_location & LOCATION_NOT_DSP_ERR_42SH) != 0)
		return (PARSING_FALTURE_42SH);
	array->env.exit_status->number = STATUS_FALTURE_42SH;
	if (ft_42sh_pipe_test_fd(array, STDERR_FILENO) == 0)
		return (PARSING_FALTURE_42SH);
	err = &array->err;
	ft_write_buffer(&array->out);
	ft_write_buffer_str_zero(err, array->msg.pre_msg_sp);
	ft_write_buffer_str_zero(err, WAR_42SH);
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		fn_script(array, err, add);
	else
		ft_write_buffer_str_zero(err, PROG_42SH);
	ft_write_buffer_str_zero(err, str);
	ft_write_buffer_str_zero(err, PRTF_RESET);
	ft_write_buffer_str(err, add, n);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer(err);
	return (PARSING_FALTURE_42SH);
}
