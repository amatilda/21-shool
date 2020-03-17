/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_alias_free(register t_main_42sh *array)
{
	t_pguitar_alias_42sh *list;
	t_pguitar_alias_42sh *list_next;

	list = array->pguitar.list;
	if (array->pguitar.f_modif.home)
		free(array->pguitar.f_modif.home);
	while (list)
	{
		list_next = list->next;
		free(list);
		list = NULL;
		list = list_next;
	}
}

static void		fn_free(register t_main_42sh *array)
{
	ft_42sh_auto_free_all_cmd(array);
	if (array->lp_spl_path != 0)
		ft_strsplit_free(array->lp_spl_path);
	ft_free(array->pwd.path.buff);
	ft_free(array->pwd.prev_path.buff);
	ft_42sh_list_fun(&array->env.root, ft_free);
	ft_42sh_jobs_free_all(array);
}

void			ft_42sh_cm_exit_fun(register t_main_42sh *array,
register size_t exit_code)
{
	fn_free(array);
	exit((unsigned char)exit_code);
}

static size_t	fn_test_err(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*b;
	register unsigned char		litter;

	if (lp_arg == 0)
		return (1);
	if ((b = (void *)lp_arg[0]) != 0 && lp_arg[1] != 0)
	{
		ft_42sh_dsp_err_msg(array, MSG_EXIT_TOO_42SH);
		return (0);
	}
	while ((litter = b[0]) != 0 && litter >= 0x30 && litter <= 0x39)
		b++;
	if (litter != 0)
	{
		ft_42sh_dsp_err_msg(array, MSG_EXIT_NUM_42SH);
		return (0);
	}
	return (1);
}

void			ft_42sh_cm_exit(register t_main_42sh *array,
register char **lp_arg)
{
	register size_t				tempos;

	if (fn_test_err(array, lp_arg) == 0)
		return ;
	if (ft_42sh_jobs_exit_test(array, lp_arg) == 0)
	{
		array->env.exit_status->number = STATUS_JOBS_STOP_42SH;
		return ;
	}
	if (lp_arg == 0 || lp_arg[0] == 0)
		tempos = E_CODE_42SH;
	else
		tempos = (unsigned char)ft_atoi(lp_arg[0]);
	fn_free(array);
	ioctl(array->fd, TIOCSETA, &array->tty);
	ft_42sh_alias_file(array);
	fn_alias_free(array);
	exit(tempos);
}
