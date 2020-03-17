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

void				*ft_42sh_dq_test_hrdc_cmp(register unsigned char *cmp,
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
			tempos = ft_strncmp((char *)cmp, (char *)b, n);
		else if (count > n + 2 && b[n + 1] == '\n')
			tempos = ft_strncmp((char *)cmp, (char *)b, n);
		if (tempos == 0)
			break ;
		while (b < end && b[0] != '\n')
			b++;
	}
	return (fn_finish(out, b, cmp, tempos));
}
