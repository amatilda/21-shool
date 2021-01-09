/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_skip.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_replase.h"

void			ft_42sh_replase_skip(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	register unsigned char	lit;

	*out = ft_42sh_parsing_sp(*out, e);
	lit = 0x20;
	while ((lit = ft_42sh_parsing_test_next(out, e, 0, lit)) != 0)
	{
		if (lit == '\\')
			ft_42sh_replase_slesh_count(out, e);
		else if (lit == '"' || lit == '\'')
			ft_42sh_dq_skip_dq(out, e, lit);
		else if (lit == '$' && *out < e && *out[0] == '{')
			ft_42sh_exp_pars_exp_skip(out, e);
	}
	*out = ft_42sh_parsing_sp(*out, e);
	(void)array;
}
