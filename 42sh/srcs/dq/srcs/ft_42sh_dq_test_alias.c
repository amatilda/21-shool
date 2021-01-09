/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_alias.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static void		fn_set(register t_main_42sh *array,
register t_pguitar_alias_42sh *alias, register size_t offset,
register size_t n)
{
	register t_alias_42sh		*list;
	register size_t				n_cnt;

	n_cnt = alias->n_cnt;
	if ((list = ft_malloc(sizeof(t_alias_42sh) + n_cnt + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	if (array->dq.first_alias == 0)
	{
		array->dq.first_alias = list;
		array->dq.last_alias = list;
	}
	else
		array->dq.last_alias->next = list;
	list->next = 0;
	list->offset_end = offset + n;
	list->offset = offset;
	list->n = n_cnt;
	ft_memcpy(list->restore, alias->name, n_cnt + 1);
}

static size_t	fn_test(register t_dq_test_in_42sh *in,
register t_pguitar_alias_42sh *alias, register unsigned char *b,
register size_t n)
{
	register t_alias_42sh		*list;
	register size_t				offset;

	if (alias->n_cnt != n || ft_strncmp(alias->name, (void *)b, n) != 0)
		return (1);
	list = in->array->dq.first_alias;
	offset = (char *)b - in->list->lp_b;
	while (list != 0)
	{
		if (list->offset_end < offset && list->offset >= offset)
			return (1);
		list = list->next;
	}
	return (0);
}

static void		fn_paste(register t_in_42sh *list,
register t_pguitar_alias_42sh *alias, register unsigned char *b,
register size_t n)
{
	t_overlow_byte_in_42sh			rep;

	rep.repl = alias->value;
	rep.n_repl = alias->v_cnt;
	ft_42sh_list_in_overlow_byte(list, &rep, b, n);
}

static size_t	fn_fiish(unsigned char **out, unsigned char **end,
register t_in_42sh *list, register unsigned char *lp_b)
{
	*out = lp_b;
	*end = lp_b + list->count;
	return (0);
}

size_t			ft_42sh_dq_test_alias(register t_dq_test_in_42sh *in,
unsigned char **out, unsigned char **end, register size_t n)
{
	register t_in_42sh				*list;
	register unsigned char			*lp_b;
	register unsigned char			*b;
	register t_pguitar_alias_42sh	*alias;

	if (n == 0)
		return (1);
	b = *out;
	alias = in->array->pguitar.list;
	while (alias != 0)
	{
		if (fn_test(in, alias, b, n) == 0)
		{
			in->array->dq.slesh_alias += alias->new_line;
			list = in->list;
			fn_set(in->array, alias, (char *)b - list->lp_b, alias->v_cnt);
			fn_paste(list, alias, b, n);
			lp_b = (void *)list->lp_b;
			in->start = lp_b;
			return (fn_fiish(out, end, list, lp_b));
		}
		alias = alias->next;
	}
	return (1);
}
