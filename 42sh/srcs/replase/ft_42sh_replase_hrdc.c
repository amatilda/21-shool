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

size_t			ft_42sh_replase_hrdc_name_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	t_replase_in_42sh		in;
	unsigned char			*start;

	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_HRDC_42SH;
	start = *out;
	return (ft_42sh_replase_count(&in, &start, out, e));
}

void			ft_42sh_replase_hrdc_name(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	t_replase_in_42sh		in;

	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_HRDC_42SH;
	ft_42sh_replase(&in, dest, b, e);
}

size_t			ft_42sh_replase_hrdc_count(register t_main_42sh *array,
unsigned char *b, register unsigned char *e)
{
	register unsigned char	lit;
	register size_t			count;
	t_replase_in_42sh		in;
	unsigned char			*s;
	size_t					b_location;

	b_location = array->b_location;
	array->b_location |= LOCATION_NOT_SET_42SH;
	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_HRDC_42SH;
	s = b;
	count = 0;
	while (b < e)
	{
		lit = b++[0];
		if (lit == '$')
			count += ft_42sh_exp_parsing_count(&in, &s, &b, e);
		else if (lit != '\n')
			count++;
	}
	array->b_location = b_location;
	return (count);
}

void			ft_42sh_replase_hrdc(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char		lit;
	t_replase_in_42sh			in;
	size_t						b_location;

	b_location = array->b_location;
	array->b_location |= LOCATION_NOT_SET_42SH;
	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_HRDC_42SH;
	while (b < e)
	{
		lit = b++[0];
		if (lit == '$')
			dest = ft_42sh_exp_parsing(&in, dest, &b, e);
		else if (lit == '\n')
			dest[-1] = '\n';
		else
			dest++[0] = lit;
	}
	array->b_location = b_location;
}
