/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_combi_date.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

void		ft_42sh_dq_combi_date(register t_main_42sh *array,
register t_in_42sh *dest, register t_in_42sh *src)
{
	register size_t		count_src;
	register size_t		count_dest;
	register size_t		max;
	register char		*lp_b;

	count_src = src->count;
	count_dest = dest->count;
	max = (count_src + count_dest + 2 + BUFFER_READ_42SH) & -BUFFER_READ_42SH;
	if ((lp_b = ft_malloc(max)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memset(lp_b, 'F', max);
	dest->max = max;
	max = (size_t)dest->lp_b;
	ft_memcpy(lp_b, (char *)max, count_dest);
	lp_b[count_dest] = ' ';
	lp_b[count_dest + 1] = '\n';
	ft_memcpy(lp_b + count_dest + 2, src->lp_b, count_src);
	ft_free((char *)max);
	dest->lp_b = lp_b;
	dest->slesh_max += src->spl_slesh != 0 ? src->slesh_max + 1 : 1;
	dest->count = count_dest + count_src + 2;
	dest->count_litter = dest->count_litter +
	src->count_litter - array->msg.pre_msg_litter;
}
