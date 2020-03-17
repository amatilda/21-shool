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
	if (ioctl(STDIN_FILENO, TIOCGETA, &array->tty_change) != 0)
	{
		write(STDERR_FILENO, E_CANON_42SH, LEN_(E_CANON_42SH));
		exit(E_CANNON_CODE_42SH);
	}
	array->tty = array->tty_change;
	array->tty_change.c_lflag &= ~(ICANON | ECHO | ISIG);
	array->tty_change.c_cc[VMIN] = 1;
	array->tty_change.c_cc[VTIME] = 0;
	if (ioctl(STDIN_FILENO, TIOCSETA, &array->tty_change) != 0)
	{
		write(STDERR_FILENO, E_CANON_42SH, LEN_(E_CANON_42SH));
		exit(E_CANNON_CODE_42SH);
	}
}

