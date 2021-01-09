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
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	array->pguitar.comp.str_dup = str;
	array->pguitar.comp.str = str;
	*len = 0;
	return (str);
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
	size_t	i;
	char	*cur_dol;
	char	*tmp_cur;

	i = 0;
	tmp_cur = *cur;
	cur_dol = array->pguitar.comp.cur_dol;
	end--;
	if (*end == '/' && end > tmp_cur && *(end - 1) != '\\' && ++i)
		array->pguitar.comp.dir_dol = 1;
	while (end > tmp_cur)
	{
		if ((*end == '$' || *end == '~') && end <= cur_dol)
		{
			if (end - 1 >= tmp_cur && *(end - 1) != '\\')
			{
				if (*(end - 1) == '/' && ++i && *end == '$')
					array->pguitar.comp.dir_dol = 1;
			}
		}
		end--;
	}
	if (i > 0)
		array->pguitar.comp.slash = 1;
}

size_t			ft_42sh_auto_comp_pars_dol_and_dir(char *cur,
				register t_main_42sh *array, char *end)
{
	if ((cur + 5) <= end && *cur == '$' && *(cur + 1) == '\'' &&
		*(cur + 2) == '\\' && *(cur + 3) == 'n' && *(cur + 4) == '\'')
		return (0);
	if (((*cur == '$' && cur == array->in.in_current->lp_b &&
		!array->pguitar.comp.count_d) || (*cur == '$' &&
		*(cur - 1) != '\\' && !array->pguitar.comp.count_d)) &&
		!array->pguitar.comp.dir_dol)
		return (1);
	return (0);
}

void			ft_42sh_auto_comp_pars_without_quote(char *cur,
register t_main_42sh *array, char *end)
{
	int				type_q;
	size_t			len;
	char			*str;

	type_q = 0;
	array->pguitar.comp.slash = 0;
	str = ft_42sh_auto_pars_without_quote_init(array, cur, end, &len);
	ft_42sh_auto_comp_pars_if_dol(array, &cur, end);
	while (cur < end)
	{
		if (ft_42sh_auto_comp_pars_dol_and_dir(cur, array, end))
			ft_42sh_auto_comp_pars_dol(&cur, array, &end);
		if (cur >= end)
			break ;
		len++;
		*(str++) = *(cur++);
	}
	*str = '\0';
	array->pguitar.comp.count_str = len;
}
