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
			ft_42sh_dq_test_dq(&b, e, litter);
		else if (litter == '<' && b[0] == '<')
			break ;
	}
	*out = b + 1;
	return (litter);
}

static void				*fn_get_cmp(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e, register size_t count)
{
	register unsigned char			*cmp;

	if ((cmp = ft_malloc(count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_replase_cmd(array, cmp, b, e);
	return (cmp);
}

static void				*fn_cmp(register unsigned char *cmp,
register size_t n, unsigned char **out, register unsigned char *end)
{
	register unsigned char		*b;
	register size_t				count;

	b = *out;
	if ((count = end - b) == n)
		n = ft_strncmp((char *)cmp, (char *)b, n);
	else if (count > n + 2 && b[n + 1] == '\n')
		n = ft_strncmp((char *)cmp, (char *)b, n);
	while (b < end && b++[0] != '\n')
		;
	if (n == 0)
	{
		ft_free(cmp);
		cmp = 0;
	}
	*out = b;
	return (cmp);
}

static unsigned char	fn_free(register void *tmp)
{
	ft_free(tmp);
	return ('<');
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
	while (*b < e)
	{
		if (fn_find(b, e) == '<')
		{
			tmp = *b;
			n = ft_42sh_replase_cmd_count(array, b, e, 0);
			array->dq.hrdoc_cmp_lp = tmp;
			array->dq.hrdoc_cmp_count = n;
			tmp = fn_get_cmp(array, tmp, e, n);
			while (out < end && (tmp = fn_cmp(tmp, n, &out, end)) != 0)
				;
			if (tmp != 0)
				return (fn_free(tmp));
		}
	}
	*b = out;
	return (0);
}
