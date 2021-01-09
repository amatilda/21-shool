/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_split_dup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_dq.h"

t_slesh_42sh		**ft_42sh_dq_split_dup(register t_slesh_42sh **spl,
register size_t n)
{
	register t_slesh_42sh		**lp_out;
	register t_slesh_42sh		*spl_slesh;
	register t_slesh_42sh		*tmp;

	if (spl == 0)
		return (0);
	if ((lp_out = ft_malloc((n + 1) * sizeof(t_slesh_42sh **))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	while ((tmp = spl[0]) != 0)
	{
		if ((spl_slesh = ft_malloc(sizeof(t_slesh_42sh))) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		spl_slesh->count = tmp->count;
		spl_slesh->count_litter = tmp->count_litter;
		lp_out++[0] = spl_slesh;
		spl++;
	}
	lp_out[0] = 0;
	lp_out -= n;
	return (lp_out);
}
