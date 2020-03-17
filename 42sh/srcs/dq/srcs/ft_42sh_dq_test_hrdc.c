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

static unsigned char	fn_find(unsigned char **out, register unsigned char *e)
{
	unsigned char					*b;
	register unsigned char			litter;

	b = *out;
	litter = 0;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '"' || litter == '\'')
			ft_42sh_dq_skip_dq(&b, e, litter);
		else if (litter == '$' && b < e && b[0] == '{')
			ft_42sh_exp_pars_exp_skip(&b, e);
		else if (litter == '<' && b[0] == '<')
			break ;
	}
	*out = b + 1;
	return (litter);
}

static void				*fn_get_cmp(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e, register size_t n)
{
	register unsigned char			*cmp;

	array->dq.hrdoc_cmp_count = n;
	if ((cmp = array->dq.hrdoc_cmp_lp) != 0)
		return (cmp);
	if ((cmp = ft_malloc(n)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_replase_hrdc(array, cmp, b, e);
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
	if (tmp != 0)
	{
		if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
			ft_free(tmp);
		else
			return (tmp);
	}
	array->dq.hrdoc_cmp_lp = 0;
	return (0);
}

unsigned char			ft_42sh_dq_test_hrdc(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **b, register unsigned char *e)
{
	register unsigned char		*end;
	register unsigned char		*tmp;
	unsigned char				*out;
	register size_t				n;

	end = (void *)(list->lp_b + list->count);
	out = e;
	n = 0;
	while (*b < e)
	{
		if (fn_find(b, e) == '<')
		{
			tmp = *b;
			n = ft_42sh_replase_hrdc_count(array, b, e);
			tmp =  fn_get_cmp(array, tmp, e, n);
			while (out < end && (tmp = ft_42sh_dq_test_hrdc_cmp(tmp, n,
			&out, end)) != 0)
				;
			if (fn_test(array, tmp) != 0)
				return ('<');
		}
	}
	return (fn_finish(out, b, end, n));
}
