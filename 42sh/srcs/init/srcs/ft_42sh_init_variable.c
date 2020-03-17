/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

void		ft_42sh_init_variable(register t_main_42sh *array)
{
	array->b_location = LOCATION_STANDART_42SH;
	array->auto_file.spec_sym = ' ';
	array->lp_auto = &array->auto_;
	array->b_fd_close = ((1 << STDIN_FILENO) | (1 << STDOUT_FILENO) |
	(1 << STDERR_FILENO));
	array->b_hash = HASH_NOT_42SH;
	array->msg.pre_msg = PRE_MSG_42SH;
	array->msg.pre_msg_litter = PRE_MSG_LITTER_42SH;
	array->msg.pre_msg_sp = MSG_SP_42SH;
	array->out.b = &array->buff_out[0];
	array->out.max = BUFFER_OUT_42SH;
	array->out.fd = STDIN_FILENO;
	array->err.b = &array->buff_err[0];
	array->err.max = BUFFER_ERR_42SH;
	array->err.fd = STDERR_FILENO;
}
