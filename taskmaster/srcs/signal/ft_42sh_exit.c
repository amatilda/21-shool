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

void	ft_42sh_exit(register size_t exit_code, register void *name_file,
register const char *name_function, register size_t line)
{
	static char		*msg[] = {"", CRIT_PR_42SH""E_MEM_TXT_42SH""PRTF_RESET,
	CRIT_PR_42SH""E_READ_TXT_42SH""PRTF_RESET,
	CRIT_PR_42SH""E_EXE_TXT_42SH""PRTF_RESET,
	CRIT_PR_42SH""E_PIPE_TXT_42SH""PRTF_RESET,
	CRIT_PR_42SH""E_CD_TXT_42SH""PRTF_RESET,
	CRIT_PR_42SH""E_IOTL_TXT_42SH""PRTF_RESET,
	CRIT_PR_42SH""E_DUP_TXT_42SH""PRTF_RESET};
	register char	*out;

	if (exit_code != E_CODE_42SH)
	{
		out = msg[exit_code];
		write(STDERR_FILENO, out, ft_strlen(out));
		write(STDERR_FILENO, "Error in: file ", 15);
		write(STDERR_FILENO, name_file, ft_strlen(name_file));
		write(STDERR_FILENO, " line ", 6);
		write(STDERR_FILENO, " function ", 10);
		write(STDERR_FILENO, name_function, ft_strlen(name_function));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(exit_code);
	(void)line;
}
