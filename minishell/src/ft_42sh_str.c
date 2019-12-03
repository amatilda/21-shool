/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					ft_42sh_str(register t_main_42sh *array,
register t_in_42sh *list, register char *str, register char *end)
{
	while (str < end)
		ft_42sh_key_litter(array, list, str++[0], 1);
}

void					ft_42sh_str_del(register t_main_42sh *array,
register t_in_42sh *list, register size_t n)
{
	while (n-- > 0)
		ft_42sh_key_backspace(array, list);
}
