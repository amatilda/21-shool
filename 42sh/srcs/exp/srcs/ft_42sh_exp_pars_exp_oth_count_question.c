/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_oth_count_question.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static size_t	fn_set_null(register t_replase_in_42sh *in)
{
	register unsigned char 			*msg;

	if ((msg = ft_malloc(LEN_(MSG_EXP_QUEST_ERR_42SH) + LEN_(MSG_EXP_QUEST_NOT_SET_42SH) + in->exp.key_count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	in->array->pr.exit_pars.lp = msg;
	ft_memcpy(msg, MSG_EXP_QUEST_ERR_42SH, LEN_(MSG_EXP_QUEST_ERR_42SH));
	msg += LEN_(MSG_EXP_QUEST_ERR_42SH);
	ft_memcpy(msg, in->exp.key, in->exp.key_count);
	msg += in->exp.key_count;
	ft_memcpy(msg, MSG_EXP_QUEST_NOT_SET_42SH, LEN_(MSG_EXP_QUEST_NOT_SET_42SH));
	msg[LEN_(MSG_EXP_QUEST_NOT_SET_42SH)] = 0;
	in->array->pr.exit_pars.error = STATUS_FALTURE_42SH;
	return (0);
}

static size_t	fn_set(register t_replase_in_42sh *in,
register unsigned char *b, register size_t count)
{
	register unsigned char 			*msg;

	if ((msg = ft_malloc(LEN_(MSG_EXP_QUEST_ERR_42SH) + count + in->exp.key_count + 1 + 2)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	in->array->pr.exit_pars.lp = msg;
	ft_memcpy(msg, MSG_EXP_QUEST_ERR_42SH, LEN_(MSG_EXP_QUEST_ERR_42SH));
	msg += LEN_(MSG_EXP_QUEST_ERR_42SH);
	ft_memcpy(msg, in->exp.key, in->exp.key_count);
	msg += in->exp.key_count;
	msg++[0] = ':';
	msg++[0] = ' ';
	ft_memcpy(msg, b, count);
	msg[count] = 0;
	in->array->pr.exit_pars.error = STATUS_FALTURE_42SH;
	return (0);
}

size_t			ft_42sh_exp_pars_exp_oth_count_question(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end)
{
	register size_t					count;
	register t_env_42sh				*list;
	register unsigned char 			*b;
	register unsigned char 			*e;

	b = *src;
	ft_42sh_exp_pars_exp_skip(src, end);
	list = in->exp.env;
	if (list != 0 && (count = ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode)) != 0)
		return (count);
	*s = *src;
	if (in->array->pr.exit_pars.lp != 0)
		return (0);
	if ((in->array->b_location & LOCATION_NOT_DSP_ERR_42SH) != 0)
		return (0);
	e = *src;
	while (b < e && e[-1] <= 0x20)
		e--;
	if ((count = e - b - 1) == 0)
		return (fn_set_null(in));
	return (fn_set(in, b, count));
}
