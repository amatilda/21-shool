/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

static void		fn_while(void)
{
	register int		fd;

	while (0xFF)
	{
		if ((fd = dup(STDIN_FILENO)) == -1)
			ft_42sh_exit(E_DUP_CODE_42SH);
		if (fd == PIPE_MAX_SUPPORT_FD_42SH)
			break ;
		else if (fd > PIPE_MAX_SUPPORT_FD_42SH)
		{
			close(fd);
			break ;
		}
	}
}

static void		fn_close(register int fd)
{
	close(fd);
	if (open("./", O_RDONLY) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH);
	if (fd == STDERR_FILENO)
		return ;
	if ((fd = dup(STDIN_FILENO)) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH);
	close(fd);
	if (fd > STDERR_FILENO)
		return ;
	if (open("./", O_RDONLY) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH);
}

void			ft_42sh_init_fd(register t_main_42sh *array)
{
	register int		fd;

	if ((fd = dup(STDIN_FILENO)) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH);
	if (fd == PIPE_MAX_SUPPORT_FD_42SH)
		return ;
	else if (fd > PIPE_MAX_SUPPORT_FD_42SH)
	{
		close(fd);
		return ;
	}
	else if (fd <= STDERR_FILENO)
		fn_close(fd);
	fn_while();
	array->fd = dup(STDIN_FILENO);
}
