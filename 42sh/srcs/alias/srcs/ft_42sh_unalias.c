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

static void		fn_free(register t_main_42sh *array,
register t_pguitar_alias_42sh *list)
{
	register t_all_cmd_42sh		**spl;
	register t_all_cmd_42sh		*auto_list;

	spl = (t_all_cmd_42sh **)ft_42sh_spl_find((void **)
	array->lp_auto->spl_all_cmd,array->lp_auto->count_all, list->name,
	list->n_cnt);
	auto_list = spl[0];
	if (auto_list->b_type == AUTO_TYPE_ALIAS_42SH)
	{
		array->lp_auto->count_all--;
		ft_42sh_list_cut(&array->lp_auto->all_cmd,
		(t_std_key_42sh *)auto_list);
		ft_42sh_auto_free_list(auto_list);
	}
	else
		auto_list->b_type = auto_list->b_type ^ AUTO_TYPE_ALIAS_42SH;
	free(list);
}

void			ft_42sh_unalias_not_exists(register t_main_42sh *array,
register char *lp_arg)
{
	ft_write_buffer_str_zero(&array->out,
		"unalias: no such hash table element: ");
	ft_write_buffer_str_zero(&array->out, lp_arg);
	ft_write_buffer_str_zero(&array->out, "\n");
}

static size_t	ft_42sh_alias_unalias_read_alias_cycle(
register char **lp_arg, t_pguitar_alias_42sh **list,
t_pguitar_alias_42sh **prev_list, register t_main_42sh *array)
{
	while (*list && *lp_arg)
	{
		if (!ft_strncmp(*lp_arg, (*list)->name, (*list)->n_cnt) &&
			*(*lp_arg + (*list)->n_cnt) == '\0')
		{
			if (!(*prev_list))
			{
				array->pguitar.f_modif.first_list = (*list)->next;
				fn_free(array, *list);
				*list = array->pguitar.f_modif.first_list;
				if (*list == NULL)
					array->pguitar.f_modif.del_file = 1;
			}
			else
			{
				(*prev_list)->next = (*list)->next;
				fn_free(array, *list);
				*list = (*prev_list)->next;
			}
			return (0);
		}
		*prev_list = *list;
		(*list) = (*list)->next;
	}
	return (1);
}

static void		ft_42sh_alias_unalias_read_alias(register t_main_42sh *array,
register char **lp_arg)
{
	t_pguitar_alias_42sh **list;
	t_pguitar_alias_42sh *prev_list;

	list = &(array->pguitar.list);
	array->pguitar.f_modif.first_list = array->pguitar.list;
	prev_list = NULL;
	while (*lp_arg)
	{
		if (ft_42sh_alias_unalias_read_alias_cycle(lp_arg, list,
			&prev_list, array))
			ft_42sh_unalias_not_exists(array, *lp_arg);
		lp_arg++;
		(*list) = array->pguitar.f_modif.first_list;
		prev_list = NULL;
	}
	if (array->pguitar.f_modif.file == 1)
		array->pguitar.f_modif.modif = 1;
}

void			ft_42sh_unalias(register t_main_42sh *array,
register char **lp_arg)
{
	if (!(*lp_arg) || array->pguitar.list == 0)
		return ;
	array->lp_auto->count_new_alias = array->lp_auto->count_all;
	ft_42sh_alias_unalias_read_alias(array, lp_arg);
	if (array->lp_auto->count_new_alias != array->lp_auto->count_all)
	{
		ft_free(array->lp_auto->spl_all_cmd);
		ft_42sh_auto_create_array(array, array->lp_auto->all_cmd.first,
		array->lp_auto->count_all);
	}
}
