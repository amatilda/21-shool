/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_free_script(register t_main_42sh *array)
{
	ft_42sh_auto_free_all_cmd_full(array);
	if (array->lp_spl_path != 0)
	{
		ft_strsplit_free(array->lp_spl_path);
		array->lp_spl_path = 0;
	}
	ft_free(array->pwd.path.buff);
	array->pwd.path.buff = 0;
	ft_free(array->pwd.prev_path.buff);
	array->pwd.prev_path.buff = 0;
	ft_free(array->pwd.path_view);
	array->pwd.path_view = 0;
	ft_free(array->msg.hrdc);
	array->msg.hrdc = 0;
	ft_42sh_jobs_free_all(array);
	ft_42sh_alias_free(array);
}

void		ft_42sh_free_exit(register t_main_42sh *array)
{
	ft_42sh_task_deinit(array);
	ft_42sh_free_script(array);
	ft_42sh_path_logins_list_free(array);
	ft_42sh_list_fun(&array->env.root, ft_free);
}
