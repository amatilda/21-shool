/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_script.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_init.h"


static void		fn_env(register t_main_42sh *array, register char **env)
{
	t_past_sort_42sh		root;

	root = array->env.root;
	array->env.root.first = 0;
	ft_free(array->pwd.prev_path.buff);
	ft_42sh_exp_start(array, env);
	ft_42sh_list_fun(&root, ft_free);
	ft_free(env);
}

static void		fn_free(register t_main_42sh *array)
{
	register char			**sp;
	register t_in_42sh		*list;
	register t_in_42sh		*tmp;

	ft_42sh_auto_free_all_cmd(array);
	if ((sp = array->lp_spl_path) != 0)
	{
		ft_strsplit_free(sp);
		array->lp_spl_path = 0;
	}

	ft_42sh_jobs_free_all(array);
	list = array->in.in_first;
	while (list != 0)
	{
		tmp = list;
		list = list->next;
		ft_42sh_list_in_free(tmp);
	}
	array->in.in_last = 0;
}

void			ft_42sh_init_script(register t_main_42sh *array,
register char **env)
{
	fn_free(array);
	ft_42sh_init_variable(array);
	array->b_location = LOCATION_SCRIPT_42SH;
	ft_42sh_init_fd(array);
	if (ioctl(array->fd, TIOCGPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	ft_42sh_signal_initilization_script(array);
	fn_env(array, env);
}
