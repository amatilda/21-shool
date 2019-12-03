/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_spl_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		**ft_42sh_spl_find(register void **spl, register size_t max_spl,
register char *str, register size_t n)
{
	register t_std_key_42sh			*cmd;

	while ((cmd = spl[0]) != 0)
	{
		if (cmd->key_count >= n && ft_strncmp(str, cmd->lp_key, n) == 0)
			break ;
		spl++;
	}
	if (cmd == 0)
		return (0);
	return (spl);
	(void)max_spl;
}
