/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_hash_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static void			fn_find(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	register t_all_cmd_42sh			**spl;
	register size_t					n;

	n = e - b;
	if (n == 0 || (spl = (t_all_cmd_42sh **)ft_42sh_spl_find((void **)
	array->lp_auto->spl_all_cmd, array->lp_auto->count_all, (void *)b, n)) == 0
	|| spl[0]->std.key_count != n)
	{
		return (ft_42sh_dsp_err_msg_add_n(array, MSG_HASH_NOT_FIND_42SH,
		(void *)b, 0));
	}
	array->b_hash = HASH_ALL_42SH;
}

static size_t		fn_set(register t_main_42sh *array,
register unsigned char *key, register unsigned char *value)
{
	register size_t					n;

	if (array->b_hash == HASH_NOT_42SH)
		array->b_hash = HASH_ONLY_42SH;
	value[0] = 0;
	n = value++ - key;
	if (ft_42sh_auto_sort_paste(array, (void *)key, value,
	AUTO_TYPE_HASH_42SH) == 0)
		return (0);
	return (1);
}

void				ft_42sh_cm_hash_arg(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			*tmp;
	register unsigned char			litter;
	size_t							b_new;

	b_new = 0;
	while ((str = (void *)lp_arg++[0]) != 0)
	{
		tmp = str;
		while ((litter = tmp[0]) != 0 && litter != '=')
			tmp++;
		if (litter == 0)
			fn_find(array, str, tmp);
		else
			b_new += fn_set(array, str, tmp);
	}
	if (b_new == 0)
		return ;
	if (array->lp_auto->spl_all_cmd != 0)
		ft_free(array->lp_auto->spl_all_cmd);
	ft_42sh_auto_create_array(array, array->lp_auto->all_cmd.first,
	array->lp_auto->count_all);
}
