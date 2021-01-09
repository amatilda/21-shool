/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_sort_paste_cut.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static void		fn_stub(register t_env_main_42sh *env,
register t_std_key_42sh *cur)
{
	if ((((t_env_42sh *)cur)->b_type & EXP_TYPE_EVERIMENT_42SH) != 0)
		env->count_env--;
	else
		env->count_local--;
	ft_free(cur);
}

t_env_42sh		*ft_42sh_exp_sort_paste_cut(register t_env_main_42sh *env,
register t_std_key_42sh *cur, register t_env_42sh *list)
{
	register t_std_key_42sh *prev;
	register t_std_key_42sh *next;

	if (list == 0)
		return (0);
	prev = cur->prev;
	next = cur->next;
	fn_stub(env, cur);
	list->std.prev = prev;
	list->std.next = next;
	if (env->root.center == cur)
		env->root.center = list;
	if (prev == 0)
		env->root.first = list;
	else
		prev->next = (void *)list;
	if (next == 0)
		env->root.last = list;
	else
		next->prev = (void *)list;
	return (list);
}
