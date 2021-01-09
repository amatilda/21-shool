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

static void		fn_while(register int dup_fd)
{
	register int		fd;

	while (0xFF)
	{
		if ((fd = dup(dup_fd)) == -1)
			ft_42sh_exit(E_DUP_CODE_42SH, __FILE__, __func__, __LINE__);
		if (fd == FD_MAX_SUPPORT_42SH)
			break ;
		else if (fd > FD_MAX_SUPPORT_42SH)
		{
			close(fd);
			break ;
		}
	}
}

void			ft_42sh_init_fd(void)
{
	register int		fd;

	if ((fd = open("./", O_RDONLY)) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH, __FILE__, __func__, __LINE__);
	if (fd == FD_MAX_SUPPORT_42SH)
		return ;
	else if (fd > FD_MAX_SUPPORT_42SH)
	{
		close(fd);
		return ;
	}
	fn_while(fd);
}
