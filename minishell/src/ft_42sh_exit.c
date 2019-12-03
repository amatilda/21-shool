/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void	ft_42sh_exit(register size_t exit_code)
{
	static char		*msg[] = {"", E_MEM_42SH, E_READ_42SH, E_EXE_42SH};
	register char	*out;

	tcsetattr(STDOUT_FILENO, TCSANOW, &g_lp_array->tty);
	if (exit_code == E_CODE_42SH)
		exit(E_CODE_42SH);
	out = msg[exit_code];
	write(STDERR_FILENO, out, ft_strlen(out));
	exit(exit_code);
}
