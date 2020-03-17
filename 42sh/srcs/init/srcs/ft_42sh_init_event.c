/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

void		ft_42sh_init_event(register t_main_42sh *array)
{
	register pid_t				pid;

	if ((pid = fork()) == 0)
	{
		while (0xFF)
			;
	}
	else if (pid < 0)
	{
		write(STDERR_FILENO, MSG_FOOR_42SH, LEN_(MSG_FOOR_42SH));
		exit(E_FOOR_CODE_42SH);
	}
	kill(pid, SIGSTOP);
	array->pr.even_child = pid;
}
