/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_set_open.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static size_t	fn_test_read(register t_main_42sh *array,
register unsigned char *dest)
{
	struct stat				st;

	if (stat((void *)dest, &st) != 0)
	{
		ft_42sh_jobs_set_err(array, MSG_EXE_NOT_42SH, dest,
		STATUS_FALTURE_42SH);
		return (0);
	}
	if ((st.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_42sh_jobs_set_err(array, MSG_IS_DIR_42SH, dest,
		STATUS_FALTURE_42SH);
		return (0);
	}
	return (1);
}

static size_t	fn_test_write(register t_main_42sh *array,
register unsigned char *dest)
{
	struct stat				st;

	if (stat((void *)dest, &st) != 0)
		return (1);
	if ((st.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_42sh_jobs_set_err(array, MSG_IS_DIR_42SH, dest,
		STATUS_FALTURE_42SH);
		return (0);
	}
	return (1);
}

size_t			ft_42sh_pipe_pre_set_open(register t_main_42sh *array,
register t_pipe_42sh *pipe, register unsigned char *dest)
{
	register int			fd;

	if (((fd = pipe->b_flag) & PIPE_LEFT_42SH) != 0)
	{
		if (fn_test_read(array, dest) == 0)
			return (0);
		fd = open((char *)dest, O_RDONLY);
	}
	else
	{
		if (fn_test_write(array, dest) == 0)
			return (0);
		fd = open((char *)dest, O_CREAT | O_RDWR | ((fd &
		(PIPE_RIGHT2_42SH ^ PIPE_RIGHT_42SH)) != 0 ? O_APPEND : O_TRUNC),
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	if (fd == -1)
	{
		ft_42sh_jobs_set_err(array, MSG_EXE_DEFINE_42SH, dest,
		STATUS_FALTURE_42SH);
		return (0);
	}
	pipe->fd_2 = fd;
	return (1);
}
