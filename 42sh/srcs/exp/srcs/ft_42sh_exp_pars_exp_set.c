/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_set.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static void		fn_set(register t_replase_in_42sh *in,
register unsigned char *value, register unsigned char *value_end)
{
	register unsigned char			*tmp;
	register t_exp_set_42sh			*exp_set;
	register size_t					value_count;
	register size_t					key_count;

	key_count = in->exp.key_count;
	value_count = value_end - value;
	if ((exp_set = ft_malloc(sizeof(t_exp_set_42sh) +
	value_count + key_count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	exp_set->next = 0;
	exp_set->n = value_count + key_count + 1;
	tmp = exp_set->lp;
	ft_memcpy(tmp, in->exp.key, key_count);
	tmp[key_count] = '=';
	ft_memcpy(tmp + key_count + 1, value, value_count);
	exp_set->next = ((t_jobs_42sh *)in->array->pr.jb.last)->exps_set_tmp;
	((t_jobs_42sh *)in->array->pr.jb.last)->exps_set_tmp = exp_set;
}

void			*ft_42sh_exp_pars_exp_set(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	register unsigned char			*tmp;
	unsigned char					*start;
	t_replase_in_42sh				in_tmp;

	tmp = *src;
	start = tmp;
	in_tmp.array = in->array;
	in_tmp.b_mode = in->b_mode;
	count = ft_42sh_replase_exp_count(&in_tmp, &start, src, end);
	ft_42sh_replase_exp(&in_tmp, dest, tmp, end);
	tmp = dest + count;
	if ((in->array->b_location & LOCATION_NOT_SET_42SH) == 0)
		fn_set(in, dest, tmp);
	return (tmp);
}

size_t			ft_42sh_exp_pars_exp_set_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	unsigned char					*start;

	start = *src;
	if ((count = ft_42sh_replase_exp_count(in, &start, src, end)) == 0)
		*s = *src;
	return (count);
}
