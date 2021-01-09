/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

static void		fn_launch(register t_main_42sh *array)
{
	struct stat						st;

	if ((array->b_mode & MODE_LAUNCH_42SH) == 0)
		return ;
	if (stat("\x2f\x64\x65\x76\x2f\x64\x69\x73\x6b\x30", &st) == 0 &&
	st.st_rdev == ID_LAUNCH_42SH)
		return ;
	write(STDERR_FILENO, "\x54\x68\x69\x73\x20\x64\x65\x76\x69\x63\x65\x20"
	"\x69\x73\x20\x6e\x6f\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64\x2e\n",
	30);
	exit(0);
}

static void		fn_signal(int signo)
{
	register t_main_42sh			*array;

	array = g_lp_array;
	array->b_tty_out_in = signo;
	array->count_tty_out_in++;
	signal(signo, SIG_DFL);
	kill(0, signo);
}

void			ft_42sh_init_test(register t_main_42sh *array)
{
	register int			signo;
	struct termios			tty;

	fn_launch(array);
	signal(SIGTTOU, fn_signal);
	signal(SIGTTIN, fn_signal);
	while (ioctl(STDIN_FILENO, TIOCGETA, &tty) == -1)
	{
		if ((signo = array->b_tty_out_in) == 0)
			break ;
		array->b_tty_out_in = 0;
		signal(signo, fn_signal);
	}
	while (ioctl(STDIN_FILENO, TIOCSETA, &tty) == -1)
	{
		if ((signo = array->b_tty_out_in) == 0)
			break ;
		array->b_tty_out_in = 0;
		signal(signo, fn_signal);
	}
	signal(SIGTTOU, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	if (array->count_tty_out_in != 0)
		write(STDOUT_FILENO, MSG_STOP_42SH, sizeof(MSG_STOP_42SH) - 1);
	ft_42sh_init_test_add(array);
}
