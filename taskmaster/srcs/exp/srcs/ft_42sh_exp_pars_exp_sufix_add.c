/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_sufix_add.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

void		*ft_42sh_exp_pars_exp_sufix_add_str(register t_env_42sh *list,
char *buff)
{
	if ((list->b_type & EXP_TYPE_NUMBER_42SH) == 0)
		return (list->lp_value);
	ft_itoa(buff, list->number, 10, ITOA_LOWER | ITOA_SIGNED);
	return (buff);
}

void		*ft_42sh_exp_pars_exp_sufix_add_set(register
t_replase_in_42sh *in, t_exp_in_exp_42sh *ptr, unsigned char **src,
register unsigned char *end)
{
	register unsigned char			*out;

	ptr->start = *src;
	ptr->count = ft_42sh_replase_exp_count(in, &ptr->start, src, end);
	if ((out = ft_malloc(ptr->count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_42sh_replase_exp(in, out, ptr->start, end);
	return (out);
}
