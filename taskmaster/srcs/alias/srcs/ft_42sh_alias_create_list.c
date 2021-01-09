/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:07:32 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:07:38 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_alias.h"

static t_pguitar_alias_42sh	*ft_42sh_alias_create_list(register char **lp_arg,
register t_pguitar_alias_42sh *next, register t_main_42sh *array)
{
	char					*arg;
	size_t					n_cnt;
	size_t					v_cnt;
	t_pguitar_alias_42sh	*list;

	if (!(arg = ft_42sh_alias_pars_name(*lp_arg, &n_cnt, array)))
		return (NULL);
	arg = ft_42sh_alias_pars_value(array, arg, &v_cnt);
	if ((list = ft_malloc(sizeof(t_pguitar_alias_42sh) + n_cnt
	+ v_cnt + 2)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	list->n_cnt = n_cnt;
	list->v_cnt = v_cnt;
	list->name = list->lp;
	list->value = list->lp + list->n_cnt + 1;
	list->next = next;
	ft_42sh_alias_fill_list(list, arg, *lp_arg);
	list->n_quote = ft_42sh_exp_shield((unsigned char*)list->name,
		(unsigned char*)(list->name + list->n_cnt));
	list->v_quote = ft_42sh_exp_shield((unsigned char*)list->value,
		(unsigned char*)(list->value + list->v_cnt));
	list->new_line = array->pguitar.f_modif.new_line;
	ft_42sh_auto_sort_paste(array, list->name, 0, AUTO_TYPE_ALIAS_42SH);
	return (list);
}

static t_pguitar_alias_42sh	*ft_42sh_alias_recreate_list(register char **lp_arg,
register t_pguitar_alias_42sh **list, register t_main_42sh *array, size_t i)
{
	register char					*value;
	t_pguitar_alias_42sh			*list_tmp;
	register t_pguitar_alias_42sh	*tmp_next;

	value = *lp_arg + (*list)->n_cnt + 1;
	if (ft_strncmp(value, (*list)->value, (*list)->v_cnt) == 0 &&
		*(value + (*list)->v_cnt) == '\0')
		return (*list);
	if (array->pguitar.f_modif.file == 1)
		array->pguitar.f_modif.modif = 1;
	tmp_next = (*list)->next;
	ft_free(*list);
	*list = NULL;
	list_tmp = ft_42sh_alias_create_list(lp_arg, tmp_next, array);
	if (i)
		array->pguitar.f_modif.first_list = list_tmp;
	return (list_tmp);
}

static void					ft_42sh_alias_create_list_next_cycle(
register char **lp_arg, t_pguitar_alias_42sh **list,
t_pguitar_alias_42sh **prev_list, register t_main_42sh *array)
{
	while (*list && *lp_arg)
	{
		if (!ft_strncmp(*lp_arg, (*list)->name, (*list)->n_cnt) &&
			*(*lp_arg + (*list)->n_cnt) == '=')
		{
			if (!(*prev_list))
				*list = ft_42sh_alias_recreate_list(lp_arg, list, array, 1);
			else
				(*prev_list)->next = ft_42sh_alias_recreate_list(lp_arg,
					list, array, 0);
			break ;
		}
		if (!((*list)->next))
		{
			(*list)->next = ft_42sh_alias_create_list(lp_arg, NULL, array);
			break ;
		}
		*prev_list = *list;
		(*list) = (*list)->next;
	}
}

static void					ft_42sh_alias_create_list_next(
register char **lp_arg, register t_main_42sh *array)
{
	t_pguitar_alias_42sh **list;
	t_pguitar_alias_42sh *prev_list;

	list = &(array->pguitar.list);
	array->pguitar.f_modif.first_list = array->pguitar.list;
	prev_list = NULL;
	while (*lp_arg)
	{
		ft_42sh_alias_create_list_next_cycle(lp_arg, list, &prev_list, array);
		lp_arg++;
		(*list) = array->pguitar.f_modif.first_list;
		prev_list = NULL;
	}
	if (array->pguitar.f_modif.file == 1)
		array->pguitar.f_modif.modif = 1;
}

void						ft_42sh_alias_pars(register t_main_42sh *array,
register char **lp_arg)
{
	if (!(*lp_arg))
		return (ft_42sh_alias_pars_dsp_all(array));
	array->lp_auto->count_new_alias = array->lp_auto->count_all;
	if (array->pguitar.list == 0)
	{
		while (!array->pguitar.list && *(lp_arg))
		{
			array->pguitar.list =
			ft_42sh_alias_create_list(lp_arg, NULL, array);
			++lp_arg;
		}
		if (*lp_arg)
			ft_42sh_alias_create_list_next(lp_arg, array);
	}
	else
		ft_42sh_alias_create_list_next(lp_arg, array);
	if (array->lp_auto->count_new_alias != array->lp_auto->count_all)
	{
		ft_free(array->lp_auto->spl_all_cmd);
		ft_42sh_auto_create_array(array, array->lp_auto->all_cmd.first,
		array->lp_auto->count_all);
	}
	ft_42sh_alias_pars_dsp_one(lp_arg, array);
}
