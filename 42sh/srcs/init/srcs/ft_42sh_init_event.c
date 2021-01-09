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
	if ((array->b_mode & MODE_SIGCHILD_42SH) == 0)
		return ;
	if (pipe(&array->pr.even_fds[0]) != 0)
		ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
}
