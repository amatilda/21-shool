/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_test_while.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

static void		fn_exit(register t_main_42sh *array, int exit_code)
{
	ft_42sh_stub_ioctl(array, TIOCSETA, &array->tty);
	exit(exit_code);
}

static void		fn_critical(register t_main_42sh *array, register size_t count,
int exit_code)
{
	write(STDERR_FILENO, CRIT_42SH"\n\x59\x6f\x75\x72\x20\x73\x79\x73\x74\x65"
	"\x6d\x20\x69\x73\x20\x75\x6e\x73\x74\x61\x62\x6c\x65\x20\x2d\x20\x74\x68"
	"\x65\x20\x73\x68\x65\x6c\x6c\x20\x63\x61\x6e\x20\x6e\x6f\x20\x6c\x6f\x6e"
	"\x67\x65\x72\x20\x63\x6f\x6e\x74\x69\x6e\x75\x65\x20\x69\x74\x73\x20\x77"
	"\x6f\x72\x6b\x2e\n"PRTF_RESET, 79);
	if (count >= MODE_GUARD_COUNT_42SH)
	{
		write(STDERR_FILENO, PRTF_BOLT"\x53\x6f\x72\x72\x79\x20\x6d\x79\x20"
		"\x66\x72\x69\x65\x6e\x64\x2c\x20\x62\x75\x74\x20\x79\x6f\x75\x20\x68"
		"\x61\x76\x65\x20\x6e\x6f\x74\x68\x69\x6e\x67\x20\x74\x6f\x20\x73\x68"
		"\x69\x6e\x65\x20\x68\x65\x72\x65\x20\x2d\x20\x59\x6f\x75\x72\x20\x66"
		"\x61\x76\x6f\x72\x69\x74\x65\x20\x73\x68\x65\x6c\x6c\x2e\x0a\x28\x3e"
		"\x5f\x3c\x29\n"PRTF_RESET, 89);
	}
	fn_exit(array, exit_code);
}

static size_t	fn_wait(register t_main_42sh *array, register pid_t pid,
register size_t count)
{
	int							stat_loc;

	if (waitpid(pid, &stat_loc, 0) == -1)
		fn_critical(array, count, STATUS_FALTURE_42SH);
	if (WIFEXITED(stat_loc) != 0)
		fn_exit(array, WEXITSTATUS(stat_loc));
	if (++count >= MODE_GUARD_COUNT_MAX_42SH)
		fn_critical(array, count, STATUS_FALTURE_42SH);
	write(STDERR_FILENO, "\n\x49\x74\x20\x6c\x6f\x6f\x6b\x73\x20\x6c\x69"
	"\x6b\x65\x20\x79\x6f\x75\x72\x20\x73\x79\x73\x74\x65\x6d\x20\x68\x61"
	"\x73\x20\x70\x72\x6f\x62\x6c\x65\x6d\x73\x2c\x20\x62\x75\x74\x20\x74"
	"\x68\x65\x20\x73\x68\x65\x6c\x6c\x20\x77\x61\x73\x20\x73\x74\x69\x6c"
	"\x6c\x20\x61\x62\x6c\x65\x20\x74\x6f\x20\x72\x65\x73\x74\x6f\x72\x65"
	"\x20\x77\x6f\x72\x6b\x69\x6e\x67\x20\x65\x66\x66\x69\x63\x69\x65\x6e"
	"\x63\x79.\n", 101);
	return (count);
}

void			ft_42sh_init_test_while(register t_main_42sh *array)
{
	register pid_t				pid;
	register size_t				count;

	if ((array->b_mode & MODE_GUARD_42SH) == 0)
		return ;
	ft_42sh_init_test_while_signal_ign();
	count = 0;
	while (0xFF)
	{
		if ((pid = fork()) == 0)
			return (ft_42sh_init_test_while_signal_dfl());
		else if (pid < 0)
		{
			write(STDERR_FILENO, WAR_PR_42SH""MSG_FOOR_TXT_42SH""PRTF_RESET,
			sizeof(WAR_PR_42SH""MSG_FOOR_TXT_42SH""PRTF_RESET) - 1);
			fn_exit(array, E_FOOR_CODE_42SH);
		}
		count = fn_wait(array, pid, count);
	}
}
