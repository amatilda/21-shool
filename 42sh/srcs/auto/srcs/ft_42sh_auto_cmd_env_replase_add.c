/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_replase_add.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

void		*ft_42sh_auto_cmd_env_replase_get(register t_main_42sh *array,
register unsigned char *b, register unsigned char **e)
{
	register size_t				count;
	unsigned char				*tmp;
	unsigned char				*start;
	t_replase_in_42sh			in;
	t_shield_out_42sh			lp;

	in.array = array;
	in.b_mode = PARSING_MODE_ARG_42SH;
	tmp = b;
	start = b;
	if ((count = ft_42sh_replase_count(&in, &start, &tmp, *e)) == 0)
		return (0);
	if ((tmp = ft_malloc(count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_replase(&in, tmp, b, *e);
	start = ft_42sh_str_shield(tmp, tmp + count, SHIELD_EXTERNALLY, &lp);
	ft_free(tmp);
	*e = start + lp.count;
	return (start);
}

void		ft_42sh_auto_cmd_env_replase_del(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register unsigned char *e)
{
	register unsigned char		*cur;
	register size_t				n;

	cur = (void *)list->lp_current;
	if (cur > e)
	{
		n = cur - e;
		ft_42sh_dsp_caret_left(array, list,
		ft_42sh_parsing_litter_n((char *)e, (char *)(e + n)), n);
	}
	else if (e > cur)
	{
		n = e - cur;
		ft_42sh_dsp_caret_right(array, list, ft_42sh_parsing_litter_n((char *)cur,
		(char *)(cur + n)), n);
	}
	ft_42sh_str_delete(array, list, (void *)b,
	ft_42sh_parsing_litter_n((char *)b, (char *)e));
}
