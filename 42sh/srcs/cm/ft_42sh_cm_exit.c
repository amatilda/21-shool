/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_cm_exit_fun(register t_main_42sh *array,
register size_t exit_code)
{
	ft_42sh_free_exit(array);
	exit((unsigned char)exit_code);
}

static size_t	fn_test_err(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*b;
	register unsigned char		litter;

	if (lp_arg == 0 || (b = (void *)lp_arg[0]) == 0)
		return (1);
	if (lp_arg[1] != 0)
	{
		ft_42sh_dsp_err_msg(array, WAR_42SH""MSG_EXIT_TOO_TXT_42SH""PRTF_RESET);
		return (0);
	}
	while ((litter = b[0]) != 0 && litter >= 0x30 && litter <= 0x39)
		b++;
	if (litter != 0)
	{
		ft_42sh_dsp_err_msg(array, WAR_42SH""MSG_EXIT_NUM_TXT_42SH""PRTF_RESET);
		return (0);
	}
	return (1);
}

void			ft_42sh_cm_exit(register t_main_42sh *array,
register char **lp_arg)
{
	register size_t				tempos;

	if (fn_test_err(array, lp_arg) == 0)
		return ;
	if (ft_42sh_jobs_exit_test(array, lp_arg) == 0)
	{
		array->env.exit_status->number = STATUS_JOBS_STOP_42SH;
		return ;
	}
	if (lp_arg == 0 || lp_arg[0] == 0)
		tempos = E_CODE_42SH;
	else
		tempos = (unsigned char)ft_atoi(lp_arg[0]);
	if ((array->b_location & LOCATION_SCRIPT_42SH) == 0)
		ft_42sh_alias_file(array);
	if ((array->b_location & LOCATION_STANDART_42SH) != 0)
		write(array->out.fd, "\n", 1);
	ft_42sh_stub_ioctl(array, TIOCSETA, &array->tty);
	ft_42sh_free_exit(array);
	exit(tempos);
}
