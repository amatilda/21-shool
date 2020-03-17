/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:07:32 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:07:38 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

static void	ft_42sh_auto_comp_dsp_all_files(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char *str;
	register char *end_str;

	str = ft_strjoin(array->pguitar.comp.dirr + array->pguitar.comp.del,
		array->pguitar.comp.str);
	end_str = str + array->pguitar.comp.count_str +
		array->pguitar.comp.count_dirr - array->pguitar.comp.del;
	ft_42sh_str_delete(array, list, array->pguitar.comp.cur,
		array->pguitar.comp.count_cur_litter);
	ft_42sh_str_add(array, str, end_str, 0);
	ft_42sh_auto_cmd(array, list, 0, 0);
	free(str);
}

static void	ft_42sh_auto_comp_word(register t_main_42sh *array,
register t_in_42sh *list)
{
	size_t			i;
	register char	b;
	register char	*str;
	register char	*end_str;
	t_all_cmd_42sh	**spl;

	str = NULL;
	end_str = NULL;
	spl = array->auto_file.spl_all_cmd;
	b = *((*spl)->std.lp_key + array->pguitar.comp.count_str);
	*((*spl)->std.lp_key + array->pguitar.comp.count_str) = '\0';
	str = ft_strjoin(array->pguitar.comp.dirr + array->pguitar.comp.del,
		(*spl)->std.lp_key);
	end_str = str + array->pguitar.comp.count_str +
		array->pguitar.comp.count_dirr - array->pguitar.comp.del;
	i = list->lp_current - list->lp_b - array->pguitar.comp.count_cur;
	ft_42sh_str_delete(array, list, array->pguitar.comp.cur,
		array->pguitar.comp.count_cur_litter);
	ft_42sh_str_add(array, str, end_str, 0);
	array->pguitar.comp.cur = (list->lp_b + i + array->pguitar.comp.count_dirr -
		array->pguitar.comp.del);
	*((*spl)->std.lp_key + array->pguitar.comp.count_str) = b;
	ft_42sh_auto_cmd(array, list, (void*)(array->pguitar.comp.cur),
		array->pguitar.comp.count_str);
	free(str);
}

static void	ft_42sh_auto_comp_env(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_all_cmd_42sh **spl;

	array->lp_auto = &array->auto_env;
	if ((spl = array->lp_auto->spl_all_cmd) == 0)
	{
		ft_42sh_auto_create_array(array, array->env.root.first,
			array->env.count_env + array->env.count_local);
		spl = array->lp_auto->spl_all_cmd;
	}
	if (array->pguitar.comp.figure)
		ft_42sh_auto_cmd(array, list, (void*)(array->pguitar.comp.dollar),
			array->pguitar.comp.count_d);
	else
		ft_42sh_auto_cmd(array, list, (void*)(array->pguitar.comp.dollar),
			array->pguitar.comp.count_d - 1);
	ft_42sh_auto_comp_free_struct(array);
	return ;
}

static void	ft_42sh_auto_comp(register t_main_42sh *array,
register t_in_42sh *list, register char *start, register char *end)
{
	ft_42sh_auto_comp_right_pars_quote(array, list, start, end);
	if (array->lp_auto->b_limit != 0 || (array->lp_auto->b_auto != 0
		&& !(*(array->pguitar.comp.str))))
	{
		ft_42sh_auto_comp_free_strdup(array);
		ft_42sh_auto_cmd(array, list, 0, 0);
		if (array->litter[0] == 110)
			return (ft_42sh_auto_toogle(array));
		return ;
	}
	if (array->lp_auto->all_cmd.first != 0 && array->lp_auto->b_auto == 0)
	{
		ft_42sh_auto_toogle(array);
		array->lp_auto = &array->auto_file;
	}
	if (array->pguitar.comp.count_d > 0 || array->pguitar.comp.figure)
		return (ft_42sh_auto_comp_env(array, list));
	else if (!ft_42sh_auto_comp_pars_dir(array))
		return (ft_42sh_auto_comp_free_struct(array));
	if ((*(array->pguitar.comp.str) != '\0' && array->auto_file.count_all != 0)
		|| array->auto_file.count_all == 1)
		ft_42sh_auto_comp_word(array, list);
	else if (array->auto_file.count_all != 0)
		ft_42sh_auto_comp_dsp_all_files(array, list);
	ft_42sh_auto_comp_free_struct(array);
}

void		ft_42sh_auto_comp_init_struct(register t_main_42sh *array,
register t_in_42sh *list, register char *start, register char *end)
{
	static size_t i;

	if (list->lp_b == list->lp_current)
		return ;
	array->pguitar.comp.dirr = NULL;
	array->pguitar.comp.open_dirr = NULL;
	array->pguitar.comp.count_str = 0;
	array->pguitar.comp.str = NULL;
	array->pguitar.comp.str_dup = NULL;
	array->pguitar.comp.cur = list->lp_current;
	array->pguitar.comp.type_q = 0;
	array->pguitar.comp.count_dirr = 0;
	array->pguitar.comp.del = 0;
	array->pguitar.comp.count_cur = 0;
	array->pguitar.comp.count_cur_litter = 0;
	array->pguitar.comp.root = &i;
	array->pguitar.comp.dollar = NULL;
	array->pguitar.comp.count_d = 0;
	array->pguitar.comp.figure = 0;
	array->pguitar.comp.caret = 0;
	array->lp_auto = &array->auto_file;
	ft_42sh_auto_comp(array, list, start, end);
}
