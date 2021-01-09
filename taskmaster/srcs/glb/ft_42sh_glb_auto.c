/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_glb_auto.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_glb.h"

static void		fn_view(register t_main_42sh *array,
register t_in_42sh *list, register t_glb_list *glb)
{
	register t_glb_list				*glb_tmp;
	register void					*b;
	t_shield_out_42sh				lp;
	t_add_litter_42sh				in;

	while (glb != 0)
	{
		b = &glb->name[0];
		b = ft_42sh_str_shield(b, b + ft_strlen(b), SHIELD_EXTERNALLY, &lp);
		in.count = lp.count;
		in.count_litter = lp.count_litter;
		ft_42sh_str(array, list, b, &in);
		ft_free(b);
		glb_tmp = glb;
		glb = glb->next;
		ft_free(glb_tmp);
		if (glb != 0)
		{
			in.count = 1;
			in.count_litter = 1;
			ft_42sh_str(array, list, (void *)" ", &in);
		}
	}
	array->glb.first = 0;
}

static void		fn_delete(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t n)
{
	register unsigned char			*current;
	register unsigned char			*e;

	e = b + n;
	if ((current = (void *)list->lp_current) != b)
		ft_42sh_dsp_caret_left(array, list, ft_strlen_utf8_n((void *)b,
		(void *)current), current - b);
	ft_42sh_str_delete(array, list, (void *)e, ft_strlen_utf8_n((void *)b,
	(void *)e));
}

static size_t	fn_finish_free(register unsigned char *tmp)
{
	ft_free(tmp);
	return (0);
}

size_t			ft_42sh_glb_auto_cmd(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n)
{
	register unsigned char			*tmp;
	register t_glb_list				*glb;
	register size_t					count;

	if (n == 0)
		return (0);
	if ((tmp = ft_strndup((void *)str, n)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	glb = ft_42sh_glb(array, (char *)tmp);
	count = 0;
	while (glb != 0)
	{
		count++;
		glb = glb->next;
	}
	glb = array->glb.first;
	if (count == 0 || (count == 1 && ft_strcmp((char *)tmp,
	&glb->name[0])) != 0)
		return (fn_finish_free(tmp));
	ft_free(tmp);
	fn_delete(array, list, str, n);
	fn_view(array, list, glb);
	return (1);
}

void			ft_42sh_glb_auto_other(register t_main_42sh *array,
register t_in_42sh *list, register char *start, register char *end)
{
	if (ft_42sh_glb_auto_cmd(array, list, (void *)start, end - start) == 1)
		return ;
	ft_42sh_auto_comp_init_struct(array, list, start, end);
}