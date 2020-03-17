/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_overlow_byte.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_offset(register t_in_42sh *list,
register t_overlow_byte_in_42sh *rep, register unsigned char *b,
register size_t n_org)
{
	register size_t				n_repl;
	register unsigned char		*tmp;
	register unsigned char		*current;
	register unsigned char		*end;

	tmp = (void *)(list->lp_b + list->count);
	current = b + n_org;
	if (n_org < (n_repl = rep->n_repl))
	{
		list->count += n_repl - n_org;
		if (current != tmp)
		{
			end = --tmp + (n_repl - n_org);
			while (tmp >= current)
				end--[0] = tmp--[0];
		}
	}
	else if (n_org > n_repl)
	{
		list->count -= n_org - n_repl;
		end = b + n_repl;
		while (current < tmp)
			end++[0] = current++[0];
	}
	ft_memcpy(b, rep->repl, n_repl);
}

void			ft_42sh_list_in_overlow_byte(register t_in_42sh *list,
register t_overlow_byte_in_42sh *rep, register unsigned char *b,
register size_t n_org)
{
	register char				*new;
	register char				*old;
	register size_t				n_repl;
	register size_t				tempos;

	if ((n_repl = rep->n_repl) > n_org)
		tempos = n_repl - n_org;
	else
		tempos = 0;
	if ((tempos = (list->count + tempos + (BUFFER_READ_42SH - 1))
	& -BUFFER_READ_42SH) <= list->max)
		return (fn_offset(list, rep, b, n_org));
	list->max = tempos;
	if ((new = ft_malloc(tempos)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	old = list->lp_b;
	list->lp_b = new;
	ft_memcpy(new, old, (tempos = (char *)b - old));
	new = new + tempos;
	ft_memcpy(new, rep->repl, n_repl);
	ft_memcpy(new + n_repl, old + tempos + n_org,
	list->count - tempos - n_org);
	list->count = tempos + n_repl + (list->count - tempos - n_org);
	ft_free(old);
}