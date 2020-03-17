/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_init.h"

static void			fn_variable_fun(register t_main_42sh *array)
{
	if (ioctl(array->fd, TIOCGPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (ioctl(array->fd, TIOCGWINSZ, &array->ws) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if ((array->pwd.path.buff = getcwd(0, 0)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
}

void			ft_42sh_init(register t_main_42sh *array, register int argc,
register char **argv, register char **env)
{
	ft_42sh_stop(array);
	ft_42sh_init_variable(array);
	ft_42sh_init_terminal(array);
	ft_42sh_init_fd(array);
	fn_variable_fun(array);
	ft_42sh_signal_initilization(array);

	array->in.in_first = ft_42sh_list_in_create(array, BUFFER_READ_42SH);
	ft_crc32_tabl_mirror(array->lp_crc32_mirror, CRC32_DEPTH_42SH, CRC32_POLINOM_MIRROR_42SH);
	ft_42sh_alias_pars_home(array);
	ft_42sh_alias_read_file(array, 0);
	ft_42sh_exp_start(array, env);
	(void)argc;
	(void)argv;
}
