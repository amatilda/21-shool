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

void			*ft_42sh_exp_pars_exp_set(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	register unsigned char			*tmp;
	unsigned char					*start;
	t_add_exp_42sh					rpl;


	tmp = *src;
	start = tmp;
	count = ft_42sh_replase_exp_count(in, &start, src, end);
	ft_42sh_replase_exp(in, dest, tmp, end);
	tmp = dest + count;
	rpl.b_type = EXP_TYPE_LOCAL_42SH;
	rpl.value = dest;
	rpl.value_end = tmp;
	dest = in->exp.key;
	if ((in->array->b_location & LOCATION_NOT_SET_42SH) == 0)
		ft_42sh_exp_add(in->array, dest, dest + in->exp.key_count, &rpl);
	return (tmp);
}

void			ft_42sh_exp_pars_exp_set_count(register t_replase_in_42sh *in)
{
	register unsigned char			*tmp;
	t_add_exp_42sh					rpl;

	if ((in->array->b_location & LOCATION_NOT_SET_42SH) != 0)
		return ;
	tmp = (void *)"";
	rpl.b_type = EXP_TYPE_LOCAL_42SH;
	rpl.value = tmp;
	rpl.value_end = tmp;
	tmp = in->exp.key;
	ft_42sh_exp_add(in->array, tmp, tmp + in->exp.key_count, &rpl);
}