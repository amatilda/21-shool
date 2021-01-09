/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_test_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static size_t	fn_test_fd(register unsigned char *str)
{
	register unsigned char			litter;
	register unsigned char			*tmp;
	struct termios					tty;

	if (str == 0)
	{
		if (ioctl(STDOUT_FILENO, TIOCGETA, &tty) == -1)
			return (STATUS_FALTURE_42SH);
		return (STATUS_OK_42SH);
	}
	tmp = str;
	while ((litter = str[0]) != 0 && litter >= 0x30 && litter <= 0x39)
		str++;
	if (litter != 0)
		return (STATUS_FALTURE_42SH);
	if (ioctl(ft_atoi((void *)tmp), TIOCGETA, &tty) == -1)
		return (STATUS_FALTURE_42SH);
	return (STATUS_OK_42SH);
}

size_t			ft_42sh_cm_test_two(register t_main_42sh *array,
register char **lp_arg, register unsigned char *str)
{
	register unsigned char			litter;

	litter = str[1];
	str = (void *)lp_arg++[0];
	if (litter == 't')
		return (fn_test_fd(str));
	else if (litter == 'n')
		return ((str[0] == 0) ? STATUS_FALTURE_42SH : STATUS_OK_42SH);
	else if (litter == 'z')
		return ((str[0] == 0) ? STATUS_OK_42SH : STATUS_FALTURE_42SH);
	return (ft_42sh_cm_test_path(array, lp_arg, str, litter));
}
