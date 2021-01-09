/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_unalias.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_dq.h"

static void				fn_while(register t_in_42sh *list,
register t_alias_42sh *alias_save, register unsigned char *b)
{
	register t_alias_42sh			*alias_tmp;
	register size_t					correction;
	register size_t					tempos;
	t_overlow_byte_in_42sh			rep;

	correction = 0;
	while (alias_save != 0)
	{
		alias_tmp = alias_save;
		alias_save = alias_save->next;
		rep.repl = (void *)alias_tmp->restore;
		rep.n_repl = alias_tmp->n;
		tempos = alias_tmp->offset;
		ft_42sh_list_in_overlow_byte(list, &rep, (b + tempos) - correction,
		alias_tmp->offset_end - tempos);
		correction += (alias_tmp->offset_end - tempos) - alias_tmp->n;
		ft_free(alias_tmp);
	}
}

void					ft_42sh_dq_unalias(register t_main_42sh *array,
register t_in_42sh *list)
{
	fn_while(list, array->dq.first_alias, (void *)list->lp_b);
	array->dq.first_alias = 0;
	array->dq.slesh_alias = 0;
}

void					ft_42sh_dq_unalias_split_re(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_alias_42sh		*alias_save;
	register t_slesh_42sh		**spl;
	register size_t				tempos;

	if ((alias_save = array->dq.first_alias) == 0)
		return ;
	array->dq.first_alias = 0;
	fn_while(list, alias_save, (void *)list->lp_b);
	if ((spl = list->spl_slesh) == 0)
		return ;
	ft_strsplit_free((char **)spl);
	list->spl_slesh = 0;
	if ((tempos = list->slesh_max - array->dq.slesh_alias) != 0)
		ft_42sh_dq_split(list, tempos);
	array->dq.slesh_alias = 0;
}

void					ft_42sh_dq_alias_spl(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_alias_42sh		*alias_save;
	register t_slesh_42sh		**spl;
	register size_t				tempos;

	if ((alias_save = array->dq.first_alias) == 0)
		return ;
	spl = list->spl_slesh;
	if ((tempos = array->dq.slesh_alias) == 0 && spl == 0)
		return ;
	if (spl != 0)
	{
		tempos += list->slesh_max;
		ft_strsplit_free((char **)spl);
	}
	ft_42sh_dq_split(list, tempos);
}
