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

size_t			ft_42sh_auto_comp_pars_dir_tilda_slash(register
t_main_42sh *array, size_t i)
{
	if (!(array->home.lp_home))
		return (1);
	array->pguitar.comp.str += i + 1;
	array->pguitar.comp.count_str -= i + 1;
	array->pguitar.comp.str = ft_strjoin(array->home.lp_home,
	array->pguitar.comp.str);
	free(array->pguitar.comp.str_dup);
	array->pguitar.comp.str_dup = array->pguitar.comp.str;
	array->pguitar.comp.count_str += ft_strlen(array->home.lp_home);
	return (0);
}

static void		ft_42sh_auto_comp_pars_dol_cycle(char **tmp_cur, size_t *i,
				register t_main_42sh *array, register char **end)
{
	char **cur;

	cur = tmp_cur;
	while (*tmp_cur != *end && **tmp_cur != '$')
	{
		(*i)++;
		if ((**tmp_cur == '}') && (array->pguitar.comp.cur_dol <= *tmp_cur))
		{
			array->pguitar.comp.dollar = *cur;
			array->pguitar.comp.count_d = *i;
			*end = *tmp_cur;
			return ;
		}
		(*tmp_cur)++;
	}
}

void			ft_42sh_auto_comp_pars_dol(char **cur,
register t_main_42sh *array, register char **end)
{
	size_t	i;
	char	*tmp_cur;

	i = 0;
	if ((*cur + 1) == *end || ((*cur + 1) != *end && *(*cur + 1) != '{'))
	{
		array->pguitar.comp.count_d = *end - *cur;
		array->pguitar.comp.dollar = *cur + 1;
	}
	else
	{
		if ((*cur + 2) == *end && (array->pguitar.comp.figure = 1))
		{
			array->pguitar.comp.dollar = (*cur += 2);
			return ;
		}
		else
			*cur += 2;
		tmp_cur = *cur;
		ft_42sh_auto_comp_pars_dol_cycle(&tmp_cur, &i, array, end);
		array->pguitar.comp.dollar = *cur;
		array->pguitar.comp.count_d = i;
		array->pguitar.comp.figure = 1;
	}
}

void			ft_42sh_auto_comp_right_pars_quote(register t_main_42sh *array,
register t_in_42sh *list, register char *start, register char *end)
{
	size_t	i;
	char	*cur;
	char	*end_cur;
	char	*tmp_cur;

	i = 0;
	array->pguitar.comp.caret = list->lp_current;
	ft_42sh_dsp_caret_right(array, list,
	ft_42sh_parsing_litter_n(list->lp_current, end), end - list->lp_current);
	ft_42sh_auto_comp_pars_without_quote(start, array, end);
	cur = array->pguitar.comp.cur;
	tmp_cur = cur;
	end_cur = array->pguitar.comp.cur + array->pguitar.comp.count_cur;
	while (cur < end_cur && *cur != '$')
	{
		if (*cur == '\'')
		{
			if (cur == tmp_cur)
				i++;
			else if (*(cur - 1) != '\\')
				i++;
		}
		cur++;
	}
	array->pguitar.comp.count_d = i % 2 ? 0 : array->pguitar.comp.count_d;
}
