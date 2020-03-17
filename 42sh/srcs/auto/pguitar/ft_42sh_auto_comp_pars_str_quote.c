/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp_pars_str_quote.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:05 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:08 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

static char		*ft_42sh_auto_pars_without_quote_init(register t_main_42sh
				*array, register char *cur, register char *end, size_t *len)
{
	register char *str;

	*len = end - cur;
	array->pguitar.comp.cur_dol = array->pguitar.comp.cur;
	array->pguitar.comp.cur = cur;
	array->pguitar.comp.count_cur = *len;
	array->pguitar.comp.count_cur_litter = ft_42sh_parsing_litter_n(cur, end);
	if (!(str = (char *)malloc(sizeof(char) * (*len + *len) + 1)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	array->pguitar.comp.str_dup = str;
	array->pguitar.comp.str = str;
	*len = 0;
	return (str);
}

static size_t	ft_42sh_auto_comp_pars_slash(char **cur,
				char **str, size_t *len, size_t type_q)
{
	if (type_q != 0 && **cur == '\\')
	{
		(*len)++;
		**str = **cur;
		*(*str + 1) = '\\';
		(*cur)++;
		(*str) += 2;
		return (1);
	}
	else if (type_q == 0 && **cur == '\\' && *len == 0)
	{
		(*cur)++;
		return (1);
	}
	return (0);
}

size_t			ft_42sh_auto_comp_pars_type_quote(char **cur,
				int *type_q, char **str, size_t *len)
{
	int typeq_tmp;

	typeq_tmp = 0;
	if (*type_q == 0 && (*type_q = (**cur == '\'') ? 39 : 34))
		(*cur)++;
	else if (*type_q != (typeq_tmp = (**cur == '\'') ? 39 : 34))
	{
		**str = **cur;
		(*len)++;
		(*cur)++;
		(*str)++;
	}
	else if (**cur == *type_q && (*cur)++)
		*type_q = 0;
	return (1);
}

void			ft_42sh_auto_comp_pars_if_dol(register t_main_42sh *array,
				char **cur, char *end)
{
	char *cur_dol;
	char *tmp_cur;

	tmp_cur = *cur;
	cur_dol = array->pguitar.comp.cur_dol;
	end--;
	while (end > tmp_cur)
	{
		if (*end == '$' && end <= cur_dol)
		{
			*cur = end;
			array->pguitar.comp.count_cur = end - tmp_cur;
			array->pguitar.comp.count_cur_litter =
				ft_42sh_parsing_litter_n(tmp_cur, end);
			return ;
		}
		end--;
	}
}

void			ft_42sh_auto_comp_pars_without_quote(char *cur,
				register t_main_42sh *array, char *end)
{
	int				type_q;
	size_t			len;
	char			*str;

	type_q = 0;
	str = ft_42sh_auto_pars_without_quote_init(array, cur, end, &len);
	ft_42sh_auto_comp_pars_if_dol(array, &cur, end);
	while (cur < end)
	{
		if ((*cur == '$' && cur == array->in.in_current->lp_b &&
			!array->pguitar.comp.count_d) || (*cur == '$' &&
			*(cur - 1) != '\\' && !array->pguitar.comp.count_d))
			ft_42sh_auto_comp_pars_dol(&cur, array, &end);
		if (cur >= end)
			break ;
		if ((*cur == '\'' || *cur == '\"') && (*(cur - 1) != '\\') &&
			ft_42sh_auto_comp_pars_type_quote(&cur, &type_q, &str, &len))
			continue ;
		if (ft_42sh_auto_comp_pars_slash(&cur, &str, &len, type_q))
			continue ;
		len++;
		*(str++) = *(cur++);
	}
	*str = '\0';
	array->pguitar.comp.count_str = len;
}
