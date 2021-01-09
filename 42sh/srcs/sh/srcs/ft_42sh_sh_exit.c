/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_sh_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_sh.h"

t_main_42sh		*ft_42sh_sh_exit_zero_crit(register t_main_42sh *array,
register void *msg)
{
	register t_write_buff			*err;

	err = &array->err;
	ft_write_buffer_str_zero(err, CRIT_42SH);
	ft_write_buffer_str_zero(err, (void *)array->sh.path);
	ft_write_buffer_str_zero(err, msg);
	ft_write_buffer_str_zero(err, "\n");
	ft_write_buffer_str_zero(err, PRTF_RESET);
	return (array);
}

void			ft_42sh_sh_exit(register t_main_42sh *array,
register size_t exit_code)
{
	ft_write_buffer(&array->err);
	ft_strsplit_free(array->sh.lp_arg);
	ft_42sh_cm_exit_fun(array, exit_code);
}
