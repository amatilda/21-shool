/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_while.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

static size_t		fn_exe(register t_main_42sh *array, unsigned char **b,
register size_t count)
{
	if (count != 0)
	{
		if (ft_42sh_exe(array) == 0)
			return (1);
	}
	*b = *b + 1;
	if (*b == array->dq.hrdoc_start_lp)
		*b = array->dq.hrdoc_last_lp;
	array->dq.hrdoc_next_lp = *b;
	return (0);
}

void				ft_42sh_parsing_while(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, register unsigned char *end)
{
	register size_t			count;
	t_parsing_in_42sh		in;

	count = 0;
	array->dq.hrdoc_start_lp = 0;
	while (b < end)
	{
		ft_42sh_parsing_cmd(array, &in.cmd, &b, end);
		if ((in.lp_arg = ft_42sh_parsing_arg(array, &b, end, in.cmd.len)) != 0)
		{
			if (ft_42sh_parsing_while_availability(array, &in, b, end) == 0)
				count = ft_42sh_parsing_end(array, &b, end, count);
			else
			{
				((t_jobs_42sh *)array->pr.jb.last)->count = ++count;
				if (ft_42sh_pipe_pre(array, list, &b, end) == 0)
					count = ft_42sh_parsing_end(array, &b, end, count);
			}
		}
		else
			count = ft_42sh_parsing_end(array, &b, end, count);
		if (b == end || ft_42sh_parsing_litter_e(b[0]) == 0)
			if ((count = fn_exe(array, &b, count)) != 0)
				return ;
	}
}
