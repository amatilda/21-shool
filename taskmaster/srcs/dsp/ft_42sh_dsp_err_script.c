/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_err_script.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			*fn_finish(register unsigned char *out,
register unsigned char *tmp, register void *cmd, register size_t n_cmd)
{
	tmp = ft_memcpy(tmp, PRTF_RESET,
	sizeof(PRTF_RESET) - 1) + sizeof(PRTF_RESET) - 1;
	ft_memcpy(tmp, cmd, n_cmd);
	tmp[n_cmd] = 0;
	return (out);
}

static size_t		fn_number(register t_main_42sh *array)
{
	register unsigned char				*out;
	register unsigned char				*tmp;
	register size_t						count;

	tmp = (void *)array->in.in_current->lp_b;
	out = array->sh.lp_cmd;
	count = 1;
	while (tmp < out)
		if (tmp++[0] == '\n')
			count++;
	return (count);
}

void				*ft_42sh_dsp_err_script(register t_main_42sh *array,
register void *msg, register void *cmd, register size_t n_cmd)
{
	register size_t						n_msg;
	register size_t						count;
	register unsigned char				*out;
	register unsigned char				*tmp;
	char								buff[sizeof(size_t) * 3 + 1];

	buff[0] = ':';
	count = ft_itoa(buff + 1, fn_number(array), 10, ITOA_LOWER) + 1;
	n_msg = ft_strlen(msg);
	if (n_cmd == 0)
		n_cmd = ft_strlen(cmd);
	if ((out = ft_malloc(n_msg + n_cmd + sizeof(WAR_42SH) - 1
	+ array->sh.count_path + count + sizeof(PRTF_RESET) - 1 + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	tmp = ft_memcpy(out, WAR_42SH, sizeof(WAR_42SH) - 1) + sizeof(WAR_42SH) - 1;
	tmp = ft_memcpy(tmp, array->sh.path, array->sh.count_path)
	+ array->sh.count_path;
	tmp = ft_memcpy(tmp, buff, count) + count;
	tmp = ft_memcpy(tmp, msg, n_msg) + n_msg;
	return (fn_finish(out, tmp, cmd, n_cmd));
}
