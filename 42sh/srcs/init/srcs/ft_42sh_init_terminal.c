/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_terminal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

void		ft_42sh_init_terminal(register t_main_42sh *array)
{
	dup2(STDIN_FILENO, FD_TERMINAL_42SH);
	if (ioctl(FD_TERMINAL_42SH, TIOCGETA, &array->tty_change) == -1)
	{
		write(STDERR_FILENO, CRIT_PR_42SH""E_CANON_TXT_42SH""PRTF_RESET,
		sizeof(CRIT_PR_42SH""E_CANON_TXT_42SH""PRTF_RESET) - 1);
		exit(E_CANNON_CODE_42SH);
	}
	ft_memcpy(&array->tty, &array->tty_change, sizeof(array->tty_change));
	array->tty_change.c_lflag &= ~(ICANON | ECHO | ISIG);
	array->tty_change.c_cc[VMIN] = 1;
	array->tty_change.c_cc[VTIME] = 0;
	if (ioctl(FD_TERMINAL_42SH, TIOCSETA, &array->tty_change) == -1)
	{
		write(STDERR_FILENO, CRIT_PR_42SH""E_CANON_TXT_42SH""PRTF_RESET,
		sizeof(CRIT_PR_42SH""E_CANON_TXT_42SH""PRTF_RESET) - 1);
		exit(E_CANNON_CODE_42SH);
	}
}
