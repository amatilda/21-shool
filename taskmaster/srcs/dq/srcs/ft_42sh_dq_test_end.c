/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static size_t			fn_stub(t_dq_test_in_42sh *in,
unsigned char **out, register unsigned char *save, register unsigned char *e)
{
	register size_t					tempos;

	*out = in->start;
	if ((tempos = ft_42sh_dq_test_hrdc(in->array, in->list, out, save)) != 0)
		return (tempos);
	*out = ft_42sh_sh_comment(in->array, *out, e);
	in->start = *out;
	return (0);
}

size_t					ft_42sh_dq_test_end(register t_main_42sh *array,
t_dq_test_in_42sh *in, unsigned char **out, register unsigned char *e)
{
	register size_t					tempos;
	register unsigned char			*b;
	register unsigned char			*save;

	b = *out;
	save = b;
	if ((tempos = ft_42sh_parsing_litter_e_f_v(b, e)) == 0x2626 ||
	(unsigned char)tempos == '|')
	{
		b = ft_42sh_parsing_litter_e_f_l(b, e);
		b = ft_42sh_parsing_sp(b, e);
		if (ft_42sh_parsing_litter_e_f(b, e) == 0)
		{
			return (ft_42sh_dq_test_err_n(array,
			MSG_SINTAX_ERROR_42SH, save, b - save));
		}
		if ((tempos = (size_t)ft_42sh_dq_test_word(array, b, e, 0)) < (size_t)b)
			return ((unsigned char)tempos);
	}
	else if (tempos == '\n')
		return (fn_stub(in, out, save, e));
	*out = ft_42sh_parsing_litter_e_f_l(save, e);
	return (0);
}