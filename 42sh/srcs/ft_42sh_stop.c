/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_stop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		fn_signal(int signo)
{
	register t_main_42sh			*array;

	array = g_lp_array;
	array->b_tty_out_in = signo;
	array->count_tty_out_in++;
	signal(signo, SIG_DFL);
	kill(0, signo);
}

void			ft_42sh_stop(register t_main_42sh *array)
{
	register int			signo;
	struct termios			tty;

	signal(SIGTTOU, fn_signal);
	signal(SIGTTIN, fn_signal);
	while (ioctl(STDIN_FILENO, TIOCGETA, &tty) != 0)
	{
		if ((signo = array->b_tty_out_in) == 0)
			break ;
		array->b_tty_out_in = 0;
		signal(signo, fn_signal);
	}
	while (ioctl(STDIN_FILENO, TIOCSETA, &tty) != 0)
	{
		if ((signo = array->b_tty_out_in) == 0)
			break ;
		array->b_tty_out_in = 0;
		signal(signo, fn_signal);
	}
	signal(SIGTTOU, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	if (array->count_tty_out_in != 0)
		write(STDOUT_FILENO, MSG_STOP_42SH, LEN_(MSG_STOP_42SH));
}
