/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_litter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static size_t	fn_rank(register size_t number)
{
	register size_t				count;

	count = 1;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

unsigned char	*ft_42sh_exp_pars_exp_litter(register t_main_42sh *array,
register unsigned char *dest, register unsigned char *key,
register unsigned char *key_end)
{
	register t_env_42sh			*list;
	register size_t				number;
	char						buff[sizeof(list->number) * 8];

	if ((list = ft_42sh_list_find_key(&array->env.root, (void *)key,
	key_end - key)) == 0)
	{
		dest++[0] = 0x30;
		return (dest);
	}
	if ((list->b_type & EXP_TYPE_NUMBER_42SH) == 0)
		number = list->value_litter;
	else
		number = fn_rank(list->number);
	fn_rank(number);
	ft_memcpy(dest, buff, (number = ft_itoa(buff, number, 10, ITOA_LOWER)));
	dest += number;
	return (dest);
}

size_t			ft_42sh_exp_pars_exp_litter_count(
register t_main_42sh *array, register unsigned char *key,
register unsigned char *key_end)
{
	register t_env_42sh			*list;
	register size_t				number;

	if ((list = ft_42sh_list_find_key(&array->env.root, (void *)key,
	key_end - key)) == 0)
		return (1);
	if ((list->b_type & EXP_TYPE_NUMBER_42SH) == 0)
		number = list->value_litter;
	else
		number = fn_rank(list->number);
	return (fn_rank(number));
}
