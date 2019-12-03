/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int				fn_test_all_cmd(register unsigned char *lp_b,
register unsigned char *lp_current, register unsigned char *end)
{
	register unsigned char		*tmp;
	register unsigned char		litter;

	tmp = lp_current - 1;
	while (lp_current < end &&
	(litter = lp_current[0]) <= 0x20 && litter != ';')
		lp_current++;
	if (lp_current < end && litter != ';')
		return (0);
	while (tmp >= lp_b && (litter = tmp[0]) <= 0x20 && litter != ';')
		tmp--;
	if (tmp >= lp_b && litter != ';')
		return (0);
	return (1);
}

static unsigned char	*fn_replace(register unsigned char *str,
register size_t n)
{
	register unsigned char		*out;

	if ((out = malloc(n + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(out, str, n);
	out[n] = 0;
	return (out);
}

static int				fn_test_cmd(register t_main_42sh *array,
register unsigned char *lp_b, register unsigned char *lp_current,
register unsigned char *end)
{
	register unsigned char		*tmp;
	register unsigned char		*start;
	register unsigned char		litter;
	register size_t				n;

	tmp = lp_current - 1;
	while (tmp >= lp_b && (litter = tmp[0]) > 0x20 && litter != ';')
		tmp--;
	start = tmp;
	if (start < lp_b || litter == ';' || litter <= 0x20)
		start++;
	while (tmp >= lp_b && (litter = tmp[0]) <= 0x20 && litter != ';')
		tmp--;
	if (tmp >= lp_b && litter != ';')
		return (0);
	if (lp_current < end && (litter = lp_current[0]) > 0x20 && litter != ';')
		return (0);
	n = lp_current - start;
	tmp = fn_replace(start, n);
	ft_42sh_auto_cmd(array, tmp, n);
	free(tmp);
	return (1);
}

void					ft_42sh_key_tab(register t_main_42sh *array,
register t_in_42sh *list)
{
	register unsigned char		*lp_b;
	register unsigned char		*lp_current;
	register unsigned char		*end;

	lp_b = (unsigned char *)list->lp_b;
	end = lp_b + list->count;
	lp_current = (unsigned char *)list->lp_current;
	if (fn_test_all_cmd(lp_b, lp_current, end) != 0)
		return (ft_42sh_auto_cmd(array, 0, 0));
	if (fn_test_cmd(array, lp_b, lp_current, end) != 0)
		return ;
}
