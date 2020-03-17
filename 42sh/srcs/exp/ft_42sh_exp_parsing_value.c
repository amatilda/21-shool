/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_parsing_value.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		*fn_cmd(register unsigned char *dest,
register unsigned char *src, register unsigned char *end)
{
	register unsigned char		litter;

	while (src < end)
	{
		if ((litter = src++[0]) == '\n')
		{
			dest++[0] = '\\';
			dest++[0] = 'n';
		}
		else
			dest++[0] = litter;
	}
	return (dest);
}

static void		*fn_write(register t_env_42sh *list,
register unsigned char *dest, register size_t b_mode)
{
	register size_t				count;
	register unsigned char		*src;
	register unsigned char		*end;

	src = (void *)list->lp_value;
	count = list->value_count;
	if ((b_mode & PARSING_MODE_ARG_42SH) != 0 ||
	list->number == 0)
		return (ft_memcpy(dest, src, count) + count);
	end = src + count;
	if ((b_mode & PARSING_MODE_CMD_42SH) != 0)
		return (fn_cmd(dest, src, end));
	return (dest);
}

void			*ft_42sh_exp_parsing_value(register t_main_42sh *array,
register t_env_42sh *list, register unsigned char *dest, register size_t b_mode)
{
	register size_t				tempos;
	char						buff[sizeof(list->number) * 8];

	if ((list->b_type & EXP_TYPE_NUMBER_42SH) == 0)
		return (fn_write(list, dest, b_mode));
	else
	{
		ft_memcpy(dest, buff,
		(tempos = ft_itoa(buff, list->number, 10, ITOA_LOWER)));
		dest += tempos;
	}
	return (dest);
	(void)array;
}

size_t			ft_42sh_exp_parsing_value_count(register t_main_42sh *array,
register t_env_42sh *list, register size_t b_mode)
{
	register size_t				tempos;
	register size_t				count;

	if ((list->b_type & EXP_TYPE_NUMBER_42SH) == 0)
	{
		count = list->value_count;
		if ((b_mode & PARSING_MODE_CMD_42SH) != 0)
			return (count + list->number);
		else
			return (count);
	}
	tempos = list->number;
	count = 1;
	while (tempos > 9)
	{
		tempos = tempos / 10;
		count++;
	}
	return (count);
	(void)array;
}
