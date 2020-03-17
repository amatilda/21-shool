/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_arg_skip.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_parsing_arg_skip(register t_main_42sh *array,
unsigned char **out, register unsigned char *end)
{
	register unsigned char	*b;

	b = *out;
	while (ft_42sh_parsing_litter_e_f(b, end) != 0)
	{
		ft_42sh_replase_skip(array, out, end);
		b = *out;
		if (b == end || ft_42sh_parsing_test_pipe(b, end, 0x20) != 0)
			return ;
	}
}
