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

void	ft_42sh_auto_comp_exp_join_finish_4(register t_main_42sh *array,
register t_in_42sh *list)
{
	array->pguitar.comp.cur = list->lp_current -
	array->pguitar.comp.count_str -
	(array->pguitar.comp.count_dirr - array->pguitar.comp.del);
	array->pguitar.comp.count_cur = array->pguitar.comp.count_str +
	(array->pguitar.comp.count_dirr - array->pguitar.comp.del);
	array->pguitar.comp.count_cur_litter =
	ft_42sh_parsing_litter_n(array->pguitar.comp.cur,
	array->pguitar.comp.cur + array->pguitar.comp.count_cur);
	free(array->pguitar.comp.str);
	array->pguitar.comp.str = array->pguitar.comp.read_dir;
	array->pguitar.comp.count_str = array->pguitar.comp.count_read;
	array->pguitar.comp.str_dup = array->pguitar.comp.str;
}

void	ft_42sh_auto_comp_exp_join_finish_3(register t_main_42sh *array,
register t_in_42sh *list, char *finish)
{
	if (finish)
	{
		free(array->pguitar.comp.str_dup);
		array->pguitar.comp.read_dir = finish;
		array->pguitar.comp.count_read = ft_strlen(finish);
		finish = ft_42sh_str_shield((void*)finish, (void*)finish
		+ array->pguitar.comp.count_read, SHIELD_EXTERNALLY, 0);
		array->pguitar.comp.str = finish;
		array->pguitar.comp.count_str = ft_strlen(finish);
		array->pguitar.comp.str_dup = finish;
		ft_42sh_str_delete(array, list, array->pguitar.comp.cur +
		(array->pguitar.comp.count_dirr - array->pguitar.comp.del),
		array->pguitar.comp.count_cur_litter -
		(array->pguitar.comp.count_dirr - array->pguitar.comp.del));
		ft_42sh_str_add(array, array->pguitar.comp.str,
		array->pguitar.comp.str + array->pguitar.comp.count_str, 0);
		ft_42sh_auto_comp_exp_join_finish_4(array, list);
	}
}

void	ft_42sh_auto_comp_exp_join_finish_2(char *tmp_end,
char *tmp_start, char **finish)
{
	char	c;

	c = *tmp_end;
	*tmp_end = '\0';
	if (!(*finish))
		*finish = ft_strjoin("", tmp_start);
	else
	{
		tmp_start = ft_strjoin(*finish, tmp_start);
		free(*finish);
		*finish = tmp_start;
	}
	*tmp_end = c;
}

void	ft_42sh_auto_comp_exp_join_finish_1(char **tmp,
char *tmp_start, char **finish)
{
	if (!(*finish))
		*finish = ft_strjoin("", *tmp);
	else
	{
		tmp_start = ft_strjoin(*finish, *tmp);
		free(*finish);
		*finish = tmp_start;
	}
	free(*tmp);
}

size_t	ft_42sh_auto_comp_exp_str(register t_main_42sh *array,
char *str, register t_in_42sh *list)
{
	char	*tmp;
	char	*tmp_start;
	char	*tmp_end;
	char	*end;
	char	*finish;

	finish = NULL;
	tmp_start = str;
	tmp_end = str;
	end = tmp_start + array->pguitar.comp.count_str;
	while (tmp_start < end)
	{
		while (tmp_end < end && *tmp_end != '/')
			tmp_end++;
		if ((tmp = ft_42sh_auto_cmd_expension(array, (void*)tmp_start,
			(void*)tmp_end, array->pguitar.comp.slash)))
			ft_42sh_auto_comp_exp_join_finish_1(&tmp, tmp_start, &finish);
		else
			ft_42sh_auto_comp_exp_join_finish_2(tmp_end, tmp_start, &finish);
		tmp_start = tmp_end;
		if (tmp_end < end)
			tmp_end++;
	}
	ft_42sh_auto_comp_exp_join_finish_3(array, list, finish);
	return (1);
}
