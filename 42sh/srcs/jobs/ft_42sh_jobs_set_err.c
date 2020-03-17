/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_set_err.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_jobs.h"

void				ft_42sh_jobs_set_err(register t_main_42sh *array,
register void *msg, register void *cmd, uint_fast8_t error)
{
	register t_jobs_42sh				*jobs;

	jobs = array->pr.jb.last;
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		jobs->path = ft_42sh_dsp_err_script(array ,msg, cmd, 0);
	else
		jobs->path = ft_42sh_dsp_err_standart(msg, cmd, 0);
	jobs->b_type = jobs->b_type | AUTO_TYPE_ERROR_42SH;
	jobs->error = error;
}

void				ft_42sh_jobs_set_err_n(register t_main_42sh *array,
register void *msg, register void *cmd, register size_t n)
{
	register t_jobs_42sh				*jobs;

	jobs = array->pr.jb.last;
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		jobs->path = ft_42sh_dsp_err_script(array ,msg, cmd, n);
	else
		jobs->path = ft_42sh_dsp_err_standart(msg, cmd, n);
	jobs->b_type = jobs->b_type | AUTO_TYPE_ERROR_42SH;
	jobs->error = STATUS_FALTURE_42SH;
}
