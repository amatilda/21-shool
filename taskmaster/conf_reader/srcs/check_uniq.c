/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uniq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 15:38:21 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 15:42:05 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static int	check_uniq_next(int p)
{
	if (p == RESTART)
		return (!ft_error("Duplicate \"restart\" parameter!\n"));
	if (p == RETRIES)
		return (!ft_error("Duplicate \"retries\" parameter!\n"));
	if (p == ON_START)
		return (!ft_error("Duplicate \"on_start\" parameter!\n"));
	if (p == STOP_SIGNAL)
		return (!ft_error("Duplicate \"stop_signal\" parameter!\n"));
	if (p == STOP_WAITING)
		return (!ft_error("Duplicate \"stop_waiting\" parameter!\n"));
	if (p == SUCCESS_WAITING)
		return (!ft_error("Duplicate \"success_waiting\" parameter!\n"));
	if (p == END_CODES)
		return (!ft_error("Duplicate \"end_codes\" parameter!\n"));
	if (p == ENV)
		return (!ft_error("Duplicate \"env\" parameter!\n"));
	return (0);
}

int			check_uniq(int p, int *uniq, int i, char *str)
{
	if (uniq[p])
	{
		dprintf(fd().e, TASK_ERROR_COLOR"Error at [%d] line: %s"
		TASK_RESET"\n", i + 1, str);
		if (p == COMMAND)
			return (!ft_error("Duplicate \"command\" parameter!\n"));
		if (p == DIRP)
			return (!ft_error("Duplicate \"directory\" parameter!\n"));
		if (p == UMASK)
			return (!ft_error("Duplicate \"umask\" parameter!\n"));
		if (p == COPIES)
			return (!ft_error("Duplicate \"copies\" parameter!\n"));
		if (p == STDOUT)
			return (!ft_error("Duplicate \"stdout\" parameter!\n"));
		if (p == STDERR)
			return (!ft_error("Duplicate \"stderr\" parameter!\n"));
		return (check_uniq_next(p));
	}
	uniq[p] = 1;
	return (1);
}
