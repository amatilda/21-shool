/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_msg_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_jobs.h"

void			ft_42sh_jobs_msg_pid(register t_write_buff *out,
register pid_t pid)
{
	char						buff[sizeof(pid_t) * 3 + 2];
	register size_t				tempos;

	tempos = ft_itoa(buff, pid, 10, ITOA_LOWER);
	buff[tempos] = ' ';
	buff[tempos + 1] = 0;
	ft_write_buffer_str_zero(out, buff);
	if (5 > tempos)
		ft_write_buffer_char(out, ' ', 5 - tempos);
}

void			ft_42sh_jobs_msg_id(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test)
{
	char				buff[sizeof(uintmax_t) * 3 + 2];
	register char		*b;
	register size_t		count;

	b = buff;
	b++[0] = '[';
	count = ft_itoa(b, jobs->id, 10, ITOA_LOWER);
	b[count] = ']';
	b[count + 1] = 0;
	ft_write_buffer_str_zero(out, buff);
	count = count > 3 ? 1 : 3 - count;
	ft_write_buffer_char(out, ' ', count);
	if ((b_test & JOBS_MSG_PLUS_42SH) != 0)
		ft_write_buffer_str_zero(out, "+ ");
	else if ((b_test & JOBS_MSG_MINUS_42SH) != 0)
		ft_write_buffer_str_zero(out, "- ");
	else
		ft_write_buffer_str_zero(out, "  ");
}
