/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_sort_paste_task.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static t_env_42sh		*fn_paste(register t_env_main_42sh *env,
register t_std_key_42sh *cur, register t_env_42sh *list)
{
	register t_env_42sh		*tmp;

	if (list == 0)
		return (0);
	if (cur->prev == 0)
	{
		env->root.first = (void *)list;
		cur->prev = (void *)list;
		list->std.next = (void *)cur;
	}
	else
	{
		tmp = (void *)cur->prev;
		tmp->std.next = (void *)list;
		list->std.next = (void *)cur;
		list->std.prev = (void *)tmp;
		cur->prev = (void *)list;
	}
	return (list);
}

static t_env_42sh		*fn_last(register t_env_main_42sh *env,
register t_env_42sh *list)
{
	register t_env_42sh		*tmp;

	if (list == 0)
		return (0);
	tmp = env->root.last;
	env->root.last = (void *)list;
	tmp->std.next = (void *)list;
	list->std.prev = (void *)tmp;
	return (list);
}

static t_std_key_42sh	*fn_pre(register t_env_main_42sh *env,
register unsigned char *key, register size_t n)
{
	register t_std_key_42sh		*cur;
	register size_t				count;
	register ssize_t			tempos;

	cur = env->root.center;
	count = cur->key_count;
	count = count > n ? n : count;
	if ((tempos = ft_strncmp(cur->lp_key, key, count)) > 0 ||
	(tempos == 0 && cur->key_count > n))
		cur = env->root.first;
	return (cur);
}

static size_t			fn_cmp(register t_main_42sh *array,
register t_env_42sh *cur, register t_add_exp_42sh *in)
{
	if ((in->b_type & EXP_TYPE_EVERIMENT_42SH) != 0)
		in->b_type = in->b_type ^ EXP_TYPE_EVERIMENT_42SH;
	else
		in->b_type = in->b_type ^ EXP_TYPE_LOCAL_42SH;
	if ((cur->b_type & EXP_TYPE_EVERIMENT_42SH) != 0)
		in->b_type = in->b_type | EXP_TYPE_EVERIMENT_42SH;
	else
		in->b_type = in->b_type | EXP_TYPE_LOCAL_42SH;
	return (1);
	(void)array;
}

t_env_42sh				*ft_42sh_exp_sort_paste_task(register t_main_42sh
*array, register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in)
{
	register t_std_key_42sh		*cur;
	register size_t				n;
	register size_t				count;
	register ssize_t			tempos;

	n = key_end - key;
	cur = fn_pre(&array->env, key, n);
	while (cur != 0)
	{
		count = cur->key_count;
		count = count > n ? n : count;
		if ((tempos = ft_strncmp(cur->lp_key, key, count)) > 0 ||
		(tempos == 0 && cur->key_count > n))
			return (fn_paste(&array->env, cur,
			ft_42sh_exp_create_task(array, key, key_end, in)));
		else if (tempos == 0 && cur->key_count == n)
		{
			fn_cmp(array, (t_env_42sh *)cur, in);
			return (ft_42sh_exp_sort_paste_cut(&array->env, cur,
			ft_42sh_exp_create_task(array, key, key_end, in)));
		}
		cur = cur->next;
	}
	return (fn_last(&array->env, ft_42sh_exp_create_task(array,
	key, key_end, in)));
}
