/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

void			ft_42sh_exe_err(register t_main_42sh *array,
register char **lp_arg)
{
	ft_42sh_dsp_err_msg(array, (void *)lp_arg);
}

size_t			ft_42sh_exe_err_foor(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	ft_42sh_dsp_err_msg(array, WAR_PR_42SH""MSG_FOOR_TXT_42SH""PRTF_RESET);
	jobs->stat_loc = STATUS_FALTURE_42SH;
	return (0);
}