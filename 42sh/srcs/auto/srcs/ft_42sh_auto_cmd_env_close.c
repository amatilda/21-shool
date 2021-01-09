/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_close.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

static void		fn_fninish(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b,
register unsigned char *e)
{
	ft_42sh_dsp_caret_left(array, list,
	ft_42sh_parsing_litter_n((char *)b, (char *)e), e - b);
}

void			ft_42sh_auto_cmd_env_close(register t_main_42sh *array,
register t_in_42sh *list, register size_t n)
{
	register unsigned char			*dest;
	register unsigned char			*e;
	register unsigned char			*cur;
	register unsigned char			*b;
	unsigned char					*tmp;

	if (array->pguitar.comp.figure == 0 || array->env.b_exp_err == 0)
		return ;
	e = array->env.lp_end_exp;
	cur = (void *)list->lp_current;
	b = cur - (n + array->env.offset_auto);
	if ((dest = ft_malloc(array->env.n_exp)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	tmp = b;
	ft_42sh_auto_cmd_env_close_while(dest, &tmp, e);
	ft_42sh_dsp_caret_left(array, list,
	ft_42sh_parsing_litter_n((char *)b, (char *)cur), cur - b);
	ft_42sh_str_delete(array, list, (void *)e,
	ft_42sh_parsing_litter_n((char *)b, (char *)e));
	ft_42sh_str_add(array, (void *)dest,
	(void *)(dest + array->env.n_exp), 2);
	e = (void *)list->lp_current;
	b = (e - array->env.n_exp) + (n + array->env.offset_auto);
	ft_free(dest);
	fn_fninish(array, list, b, e);
}
