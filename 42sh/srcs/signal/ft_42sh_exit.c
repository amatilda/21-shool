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

#include "includes/ft_42sh_signal.h"

void	ft_42sh_exit(register size_t exit_code)
{
	static char		*msg[] = {"", E_MEM_42SH, E_READ_42SH, E_EXE_42SH,
	E_PIPE_42SH, E_CD_42SH, E_IOTL_42SH, E_DUP_42SH};
	register char	*out;

	if (exit_code != E_CODE_42SH)
	{
		out = msg[exit_code];
		write(STDERR_FILENO, out, ft_strlen(out));
	}
	ft_42sh_signal_term(exit_code);
}
