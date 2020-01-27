/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_parsing_cmd(register t_main_42sh *array,
register t_string *string, unsigned char **b, register unsigned char *end)
{
	register size_t			count;
	register unsigned char	*tmp;
	register unsigned char	*dest;

	tmp = *b;
	tmp = ft_42sh_parsing_sp(tmp, end);
	count = ft_42sh_replase_cmd_count(array, b, end, 0);
	string->max_len = count;
	string->len = count;
	if (tmp == *b)
		return ;
	if (count == 0)
		return (ft_42sh_dsp_err_msg(array, MSG_EXE_DEFINE_42SH));
	if ((dest = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	dest[count] = 0;
	string->buff = (char *)dest;
	ft_42sh_replase_cmd(array, dest, tmp, end);
}
