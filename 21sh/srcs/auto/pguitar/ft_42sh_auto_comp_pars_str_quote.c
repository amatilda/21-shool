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

static char		*ft_42sh_auto_pars_without_quote_init(register
t_main_42sh *array, register char *cur, register char *end, size_t *len)
{
	register char *str;

	*len = end - cur;
	array->pguitar.comp.cur = cur;
	array->pguitar.comp.count_cur = *len;
	array->pguitar.comp.count_cur_litter = ft_strlen_utf8_n(cur, end);
	if (!(str = (char *)malloc(sizeof(char) * (*len + *len) + 1)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	array->pguitar.comp.str_dup = str;
	array->pguitar.comp.str = str;
	*len = 0;
	return (str);
}

static size_t	ft_42sh_auto_comp_pars_without_quote_slash(char **cur,
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

void			ft_42sh_auto_comp_pars_without_quote(char *cur,
register t_main_42sh *array, register char *end)
{
	int				type_q;
	size_t			len;
	char			*str;

	type_q = 0;
	str = ft_42sh_auto_pars_without_quote_init(array, cur, end, &len);
	while (cur != end)
	{
		if ((*cur == '\'' || *cur == '\"') && *(cur - 1) != '\\')
		{
			if (type_q == 0 && (type_q = (*cur == '\'') ? 39 : 34))
				cur++;
			else if (*cur == type_q && cur++)
				type_q = 0;
			continue ;
		}
		if (ft_42sh_auto_comp_pars_without_quote_slash(&cur, &str,
			&len, type_q))
			continue ;
		len++;
		*(str++) = *(cur++);
	}
	*str = '\0';
	array->pguitar.comp.count_str = len;
}
