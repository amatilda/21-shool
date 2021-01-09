/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static void			fn_view(register t_write_buff *out,
register t_all_cmd_42sh *spl)
{
	char					buff[sizeof(size_t) * 3 + 1];
	register size_t			count;

	count = ft_itoa(buff, spl->count_cmd, 10, ITOA_LOWER);
	buff[count] = 0;
	ft_write_buffer_str_zero(out, buff);
	count = count > HASH_HITS_LEN_42SH ? 1 : HASH_HITS_LEN_42SH - count;
	ft_write_buffer_char(out, ' ', count);
	ft_write_buffer_str_zero(out, spl->key);
	ft_write_buffer_str_zero(out, "=");
	ft_write_buffer_str_zero(out, (spl->b_type & AUTO_TYPE_HASH_42SH) == 0 ?
	spl->path : spl->path_hash);
	if ((spl->b_type & AUTO_TYPE_HASH_42SH) == 0)
	{
		ft_write_buffer_str_zero(out, "/");
		ft_write_buffer_str_zero(out, spl->key);
	}
	ft_write_buffer_str_zero(out, "\n");
}

static void			fn_only_hash(register t_write_buff *out,
register t_all_cmd_42sh **spl_pak)
{
	register t_all_cmd_42sh			*spl;

	while ((spl = spl_pak[0]) != 0 && (spl->b_type & AUTO_TYPE_HASH_42SH) == 0)
		spl_pak++;
	if (spl != 0)
		ft_write_buffer_str_zero(out, MSG_HASH_PRE_42SH);
	while ((spl = spl_pak++[0]) != 0)
		if ((spl->b_type & AUTO_TYPE_HASH_42SH) != 0)
			fn_view(out, spl);
}

static void			fn_all(register t_main_42sh *array)
{
	register t_all_cmd_42sh			**spl_pak;
	register t_all_cmd_42sh			*spl;
	register size_t					b_hash;

	if ((b_hash = array->b_hash) == HASH_NOT_42SH)
		return ;
	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, MSG_HASH_42SH) == 0)
		return ;
	spl_pak = array->lp_auto->spl_all_cmd;
	if ((b_hash = array->b_hash) == HASH_ALL_42SH)
	{
		while ((spl = spl_pak[0]) != 0 && (spl->b_type & AUTO_TYPE_HASH_42SH)
		== 0 && spl->count_cmd == 0)
			spl_pak++;
		if (spl == 0)
			return ;
		ft_write_buffer_str_zero(&array->out, MSG_HASH_PRE_42SH);
		while ((spl = spl_pak++[0]) != 0)
			if (((((spl->b_type & AUTO_TYPE_EXE_42SH) != 0 && spl->count_cmd
			!= 0) || (spl->b_type & AUTO_TYPE_HASH_42SH) != 0)))
				fn_view(&array->out, spl);
		return ;
	}
	fn_only_hash(&array->out, spl_pak);
}

void				ft_42sh_cm_hash(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			litter;
	register size_t					b_view;

	b_view = 0;
	while ((str = (void *)lp_arg[0]) != 0 && str++[0] == '-')
	{
		lp_arg++;
		if ((litter = str[0]) == 0 || (litter == '-' && str[1] == 0))
			break ;
		while ((litter = str++[0]) != 0 && litter == 'r')
			b_view = 'r';
		if (litter != 0)
			return (ft_42sh_dsp_err_msg_add_n(array,
			WAR_PR_42SH""MSG_BAD_OPTION_TXT_42SH""PRTF_RESET"-",
			(void *)str - 1, ft_strlen_utf8_litter(str - 1)));
	}
	if (b_view != 0)
		return (ft_42sh_cm_hash_reset(array, lp_arg));
	if (lp_arg[0] == 0)
		return (fn_all(array));
	ft_42sh_cm_hash_arg(array, lp_arg);
}
