/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_hrdc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static void				*fn_get_cmp(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e, register size_t n)
{
	register unsigned char			*cmp;

	array->dq.hrdoc_cmp_count = n;
	if ((cmp = array->dq.hrdoc_cmp_lp) != 0)
		return (cmp);
	if ((cmp = ft_malloc(n)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_42sh_replase_hrdc_name(array, cmp, b, e);
	array->dq.hrdoc_cmp_lp = cmp;
	return (cmp);
}

static unsigned char	fn_finish(register unsigned char *out,
unsigned char **b, register unsigned char *end, register size_t n)
{
	out = out + n + 1;
	if (out > end)
		*b = end;
	else
		*b = out;
	return (0);
}

static void				*fn_test(register t_main_42sh *array,
register unsigned char *tmp)
{
	if ((array->dq.b_hrdoc & DQ_HRDC_ERR_42SH) != 0)
	{
		if (tmp != 0)
			ft_free(tmp);
		array->dq.hrdoc_cmp_lp = 0;
		return ((unsigned char *)PARSING_FALTURE_42SH);
	}
	if (tmp != 0)
	{
		if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
			ft_free(tmp);
		else
			return ((void *)'<');
	}
	array->dq.hrdoc_cmp_lp = 0;
	return (0);
}

static void				fn_test_dq(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	register unsigned char		litter;

	while (b < e)
	{
		if ((litter = b++[0]) == '\'' || litter == '"')
		{
			array->dq.b_hrdoc = DQ_HRDC_42SH;
			return ;
		}
	}
	array->dq.b_hrdoc = 0;
}

unsigned char			ft_42sh_dq_test_hrdc(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **b, register unsigned char *e)
{
	register unsigned char		*tmp;
	unsigned char				*out;
	t_heredoc_in_42sh			in;

	out = e;
	in.end = (void *)(list->lp_b + list->count);
	in.n = 0;
	in.array = array;
	while (*b < e)
	{
		if (ft_42sh_dq_test_hrdc_find(b, e) == '<')
		{
			tmp = *b;
			in.n = ft_42sh_replase_hrdc_name_count(array, b, e);
			fn_test_dq(array, tmp, *b);
			tmp = fn_get_cmp(array, tmp, e, in.n);
			in.cmp = tmp;
			while (out < in.end && (tmp = ft_42sh_dq_test_hrdc_cmp(&in, in.n,
			&out, in.end)) != 0)
				;
			if ((tmp = fn_test(array, tmp)) != 0)
				return ((unsigned char)tmp);
		}
	}
	return (fn_finish(out, b, in.end, in.n));
}
