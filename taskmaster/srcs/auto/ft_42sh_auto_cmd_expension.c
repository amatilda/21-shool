/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_expension.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_auto.h"

static void		*fn_test(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e,
register size_t b_test)
{
	register unsigned char				*out;
	register size_t						count;
	t_replase_in_42sh					in;
	unsigned char						*tmp;
	unsigned char						*start;

	if (ft_42sh_dq_test_word(array, b, e, 0) < b)
		return (0);
	in.array = array;
	if (b_test == 0)
		in.b_mode = PARSING_MODE_ARG_42SH;
	else
		in.b_mode = PARSING_MODE_ARG_42SH | PARSING_MODE_TILD_42SH;
	tmp = b;
	start = b;
	if ((count = ft_42sh_replase_count(&in, &start, &tmp, e)) == 0)
		return (0);
	if ((out = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	out[count] = 0;
	ft_42sh_replase(&in, out, b, e);
	return (out);
}

void			*ft_42sh_auto_cmd_expension(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e, register size_t b_test)
{
	register unsigned char				*out;
	size_t								b_location;

	b_location = array->b_location;
	array->b_location = LOCATION_STANDART_42SH | LOCATION_NOT_DSP_ERR_42SH |
	LOCATION_NOT_SET_42SH;
	out = fn_test(array, b, e, b_test);
	array->b_location = b_location;
	return (out);
}
