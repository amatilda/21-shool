/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static unsigned char	*fn_write_dsp(register t_write_buff *out,
register unsigned char *str, unsigned char **tmp,
register unsigned char litter)
{
	register unsigned char			*start;

	start = *tmp;
	ft_write_buffer_str(out, (void *)start, str - start);
	ft_write_buffer_char(out, litter, 1);
	*tmp = str + 2;
	return (str + 1);
}

static void				*fn_stub(register t_write_buff *out,
register unsigned char *str, unsigned char **tmp,
register unsigned char litter)
{
	if (litter == 'a')
		str = fn_write_dsp(out, str, tmp, '\a');
	else if (litter == 'b')
		str = fn_write_dsp(out, str, tmp, '\b');
	else if (litter == 'f')
		str = fn_write_dsp(out, str, tmp, '\f');
	else if (litter == 'n')
		str = fn_write_dsp(out, str, tmp, '\n');
	else if (litter == 'r')
		str = fn_write_dsp(out, str, tmp, '\r');
	else if (litter == 't')
		str = fn_write_dsp(out, str, tmp, '\t');
	else if (litter == 'v')
		str = fn_write_dsp(out, str, tmp, '\v');
	else if (litter == '\\')
		str = fn_write_dsp(out, str, tmp, '\\');
	return (str);
}

static size_t			fn_write(register t_write_buff *out,
register unsigned char *str)
{
	unsigned char					*tmp;
	register unsigned char			litter;

	tmp = str;
	while ((litter = str[0]) != 0)
	{
		if (litter == '\\')
		{
			if ((litter = str[1]) == 'c')
			{
				ft_write_buffer_str(out, (void *)tmp, str - tmp);
				return (0);
			}
			else if (litter == '0')
				str = ft_42sh_cm_echo_number(out, str, &tmp);
			else
				str = fn_stub(out, str, &tmp, litter);
		}
		str++;
	}
	ft_write_buffer_str(out, (void *)tmp, str - tmp);
	return (1);
}

static void				fn_while(register t_write_buff *out,
register char **lp_arg)
{
	register unsigned char	*str;

	if ((str = (void *)lp_arg[0]) != 0)
	{
		if (fn_write(out, str) == 0)
			return ;
		lp_arg++;
	}
	while ((str = (void *)lp_arg++[0]) != 0)
	{
		ft_write_buffer_str_zero(out, " ");
		if (fn_write(out, str) == 0)
			return ;
	}
}

void					ft_42sh_cm_echo(register t_main_42sh *array,
register char **lp_arg)
{
	register t_write_buff	*out;
	register unsigned char	*str;
	register size_t			b_n;

	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, "echo") == 0)
		return ;
	out = &array->out;
	b_n = 1;
	while ((str = (void *)lp_arg[0]) != 0 && str[0] == '-' && str[1] == 'n' &&
	str[2] == 0)
	{
		b_n = 0;
		lp_arg++;
	}
	fn_while(out, lp_arg);
	if (b_n != 0)
		ft_write_buffer_str_zero(out, "\n");
}
