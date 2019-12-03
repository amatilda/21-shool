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

#include "ft_42sh.h"

static char		*fn_write_dsp(register t_write_buff *out, register char *str,
char **tmp, register char litter)
{
	register char			*start;

	start = *tmp;
	ft_write_buffer_str(out, start, str - start);
	ft_write_buffer_char(out, litter, 1);
	*tmp = str + 2;
	return (str + 1);
}

static void		fn_write(register t_write_buff *out, register char *str)
{
	char					*tmp;
	register char			litter;

	tmp = str;
	while ((litter = str[0]) != 0)
	{
		if (litter == '\\')
		{
			if ((litter = str[1]) == 'n')
				str = fn_write_dsp(out, str, &tmp, '\n');
			else if (litter == 't')
				str = fn_write_dsp(out, str, &tmp, '\t');
		}
		str++;
	}
	ft_write_buffer_str(out, tmp, str - tmp);
}

void			ft_42sh_cm_echo(register t_main_42sh *array,
register char **lp_arg)
{
	register t_write_buff	*out;
	register char			*str;
	register size_t			count;

	out = &array->out;
	count = 0;
	while ((str = lp_arg++[0]) != 0)
	{
		if (count != 0)
			ft_write_buffer_str_zero(out, " ");
		fn_write(out, str);
		count++;
	}
	ft_write_buffer_str_zero(out, "\n");
}
