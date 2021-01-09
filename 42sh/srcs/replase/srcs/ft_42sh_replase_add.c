/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

size_t		ft_42sh_replase_add_tilda(register t_replase_in_42sh *in,
register unsigned char *start, register unsigned char *b,
register unsigned char *e)
{
	if ((in->b_mode & PARSING_MODE_HRDC_42SH) == 0 &&
		(in->b_mode & PARSING_MODE_TILD_42SH) == 0 &&
		ft_42sh_replase_home_test(in->array, start, b, e) != 0)
	{
		return (1);
	}
	return (0);
}

void		ft_42sh_replase_add_finish(register t_replase_in_42sh *in,
size_t exps_loop)
{
	if ((in->array->b_location & LOCATION_NOT_SET_42SH) == 0 &&
	(in->b_mode & PARSING_MODE_HRDC_42SH) == 0 && exps_loop == 0)
		ft_42sh_exp_corection(in);
}
