/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_err_standart.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			*ft_42sh_dsp_err_standart(register void *msg, register void *cmd,
register size_t n_cmd)
{
	register size_t						n_msg;
	register unsigned char				*out;
	register unsigned char				*tmp;

	n_msg = ft_strlen(msg);
	if (n_cmd == 0)
		n_cmd = ft_strlen(cmd);
	if ((out = malloc(n_msg + n_cmd + LEN_(WAR_42SH) + LEN_(PROG_42SH) + LEN_(PRTF_RESET) + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	tmp = ft_memcpy(out, WAR_42SH""PROG_42SH, LEN_(WAR_42SH) + LEN_(PROG_42SH)) + LEN_(WAR_42SH) + LEN_(PROG_42SH);
	tmp = ft_memcpy(tmp, msg, n_msg) + n_msg;
	tmp = ft_memcpy(tmp, PRTF_RESET, LEN_(PRTF_RESET)) + LEN_(PRTF_RESET);
	ft_memcpy(tmp, cmd, n_cmd);
	tmp[n_cmd] = 0;
	return (out);
}