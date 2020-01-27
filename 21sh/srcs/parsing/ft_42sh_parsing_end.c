/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t			ft_42sh_parsing_end(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register size_t count)
{
	register unsigned char	litter;
	register unsigned char	dquote;
	register unsigned char	*b;

	b = *out;
	dquote = 0;
	while (b < e)
	{
		if ((litter = b[0]) == '\\')
			b++;
		else if (dquote == litter || (dquote == 0 &&
		(litter == '"' || litter == '\'')))
			dquote = (litter == dquote) ? 0 : litter;
		else if (dquote == 0 && ft_42sh_parsing_litter_e(litter) == 0)
			break ;
		b++;
	}
	*out = b;
	if (count != 0)
		ft_42sh_jobs_free_list_count_err(array, array->pr.jb.last);
	return (0);
}
