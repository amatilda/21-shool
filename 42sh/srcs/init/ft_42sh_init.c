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

void			ft_42sh_init(register t_main_42sh *array, register int argc,
register char **argv, register char **env)
{
	ft_42sh_init_test(array);
	ft_42sh_init_variable(array, LOCATION_STANDART_42SH);
	ft_42sh_init_terminal(array);
	ft_42sh_init_test_while(array);
	ft_42sh_signal_initilization(array);
	ft_42sh_init_fd();
	ft_42sh_init_event(array);
	ft_42sh_init_variable_fun(array);
	ft_42sh_list_in_create(array, BUFFER_READ_42SH);
	ft_crc32_tabl_mirror(array->lp_crc32_mirror, CRC32_DEPTH_42SH,
	CRC32_POLINOM_MIRROR_42SH);
	ft_42sh_alias_pars_home(array);
	ft_42sh_alias_read_file(array, 0);
	ft_42sh_path_logins(array);
	ft_42sh_exp_start(array, env);
	ft_42sh_task_init(array, argc, argv);
}

void			ft_42sh_init_script(register t_main_42sh *array,
register char **env, register char **lp_arg)
{
	ft_42sh_free_script(array);
	ft_42sh_init_variable(array, LOCATION_SCRIPT_42SH);
	ft_42sh_signal_initilization_script(array);
	ft_42sh_init_fd();
	ft_42sh_init_event(array);
	ft_42sh_init_variable_fun(array);
	ft_42sh_init_script_env(array, env, lp_arg);
}
