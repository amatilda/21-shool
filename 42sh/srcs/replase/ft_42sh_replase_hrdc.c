/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_hrdc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_replase.h"

size_t			ft_42sh_replase_hrdc_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	t_replase_in_42sh		in;
	unsigned char			*start;

	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_HRDC_42SH;
	start = *out;
	return (ft_42sh_replase_count(&in, &start, out, e));
}

void			ft_42sh_replase_hrdc(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	t_replase_in_42sh		in;

	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_HRDC_42SH;
	ft_42sh_replase(&in, dest, b, e);
}
