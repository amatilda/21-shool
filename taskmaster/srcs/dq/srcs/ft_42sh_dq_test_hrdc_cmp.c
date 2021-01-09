/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_hrdc_cmp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static void			*fn_finish(unsigned char **out, register unsigned char *b,
register unsigned char *cmp, register size_t tempos)
{
	*out = b;
	if (tempos == 0)
	{
		ft_free(cmp);
		return (0);
	}
	return (cmp);
}

static void			*fn_test(register t_main_42sh *array,
register unsigned char *b, register unsigned char *end)
{
	register unsigned char		*tmp;
	register size_t				b_hrdoc;

	tmp = b;
	while (b < end && b[0] != '\n')
		b++;
	if (((b_hrdoc = array->dq.b_hrdoc) & DQ_HRDC_42SH) != 0 ||
	(b_hrdoc & DQ_HRDC_ERR_42SH) != 0)
		return (b);
	end = b;
	while ((tmp = ft_42sh_parsing_sp(tmp, end)) < end)
	{
		if ((tmp = ft_42sh_dq_test_word(array, tmp, end, DQ_HRDC_42SH)) <=
		(unsigned char *)PARSING_FALTURE_42SH)
		{
			array->dq.b_hrdoc |= DQ_HRDC_ERR_42SH;
			return (end);
		}
		if (ft_42sh_parsing_litter_e_f(tmp, end) == 0)
			tmp = ft_42sh_parsing_litter_e_f_l(tmp, end);
	}
	return (end);
}

void				*ft_42sh_dq_test_hrdc_cmp(register t_heredoc_in_42sh *in,
register size_t n, unsigned char **out, register unsigned char *end)
{
	register unsigned char		*b;
	register size_t				count;
	register size_t				tempos;

	b = *out;
	tempos = 1;
	while (b < end)
	{
		if (++b == end)
		{
			tempos = n;
			break ;
		}
		if (n == 0 && b + 1 < end && b[1] == '\n')
			tempos = 0;
		else if ((count = end - b) == n)
			tempos = ft_strncmp((char *)in->cmp, (char *)b, n);
		else if (count > n + 2 && b[n + 1] == '\n')
			tempos = ft_strncmp((char *)in->cmp, (char *)b, n);
		if (tempos == 0)
			break ;
		if ((b = fn_test(in->array, b, end)) == 0)
			return ((void *)PARSING_FALTURE_42SH);
	}
	return (fn_finish(out, b, in->cmp, tempos));
}
