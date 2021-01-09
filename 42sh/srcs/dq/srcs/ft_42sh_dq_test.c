/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static unsigned char	fn_finish(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, register unsigned char *e)
{
	register unsigned char		litter;

	if (b == e)
		return (0);
	if ((litter = ft_42sh_dq_test_slh(array, b, e - b)) != 0)
		return (litter);
	return (ft_42sh_dq_test_hrdc(array, list, &b, e));
}

static void				fn_pre_set(register t_main_42sh *array,
t_dq_test_in_42sh *in, register t_in_42sh *list, unsigned char *b)
{
	in->array = array;
	in->list = list;
	in->start = b;
}

static unsigned char	fn_error(register t_main_42sh *array,
unsigned char *b, unsigned char *e)
{
	return (ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, b,
	((unsigned char *)ft_42sh_parsing_litter_e_f_l(b, e) - b)));
}

unsigned char			ft_42sh_dq_test(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, unsigned char *e)
{
	register size_t					tempos;
	t_dq_test_in_42sh				in;

	fn_pre_set(array, &in, list, b);
	b = ft_42sh_sh_comment(array, b, e);
	while ((b = ft_42sh_parsing_sp(b, e)) < e)
	{
		if ((tempos = (unsigned char)ft_42sh_parsing_litter_e_f_v(b, e)) == '&'
		|| tempos == '|')
			return (fn_error(array, b, e));
		if (ft_42sh_parsing_test_pipe(b, e, 0x20) != 0)
			if ((tempos = ft_42sh_dq_test_pipe(array, &b, e)) != 0)
				return ((unsigned char)tempos);
		if ((tempos = (size_t)ft_42sh_dq_test_word(array, b, e, 0)) < (size_t)b)
			return ((unsigned char)tempos);
		if (ft_42sh_dq_test_alias(&in, &b, &e, tempos - (size_t)b) == 0)
			continue ;
		if ((tempos = ft_42sh_dq_test_sintax(array, &b, e)) != 0)
			return ((unsigned char)tempos);
		if ((tempos = ft_42sh_dq_test_end(array, &in, &b, e)) != 0)
			return ((unsigned char)tempos);
	}
	return (fn_finish(array, list, in.start, e));
}
