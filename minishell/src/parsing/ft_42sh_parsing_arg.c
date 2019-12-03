/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void					fn_empty(register t_main_42sh *array,
unsigned char **out, register unsigned char *end)
{
	register size_t			count;

	while (*out < end &&
	(count = ft_42sh_replase_arg_count(array, out, end, 0)) != 0)
		(void)count;
	*out = *out + 1;
}

void						ft_42sh_parsing_arg(register t_main_42sh *array,
unsigned char **out, register unsigned char *end, size_t b_empty)
{
	register char			**lp_arg;
	register size_t			count;
	register unsigned char	*tmp;
	register unsigned char	*b;

	if (b_empty == 0)
		return (fn_empty(array, out, end));
	b = *out;
	count = ft_42sh_replase_arg_big(array, b, end);
	if ((lp_arg = malloc(sizeof(char *) * (count + 1 + 1))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	array->lp_arg = lp_arg;
	lp_arg++[0] = 0;
	lp_arg[count] = 0;
	while (b < end &&
	(count = ft_42sh_replase_arg_count(array, out, end, 0)) != 0)
	{
		if ((tmp = malloc(count + 1)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		lp_arg++[0] = (char *)tmp;
		tmp[count] = 0;
		ft_42sh_replase_arg(array, tmp, b, end);
		b = *out;
	}
	*out = *out + 1;
}
