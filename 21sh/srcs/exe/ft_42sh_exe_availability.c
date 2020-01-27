/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_availability.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t			ft_42sh_exe_availability(register t_main_42sh *array,
register char *cmd)
{
	struct stat				st;
	register size_t			mode;

	if (lstat(cmd, &st) == 0)
	{
		mode = st.st_mode;
		if (((mode & S_IXUSR) | (mode & S_IXGRP) | (mode & S_IXOTH)) != 0)
			return (1);
		else
		{
			array->exit_status = 0x7E;
			ft_42sh_dsp_err_msg_add(array, MSG_EXE_DEFINE_42SH, cmd);
		}
	}
	else
	{
		array->exit_status = 0x7F;
		ft_42sh_dsp_err_msg_add(array, MSG_EXE_NOT_42SH, cmd);
	}
	return (0);
}
