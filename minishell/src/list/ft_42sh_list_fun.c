/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_list_fun(register t_past_sort_42sh *root,
void (*f)(register void *))
{
	register t_std_key_42sh			*list;
	register t_std_key_42sh			*tmp;

	list = root->first;
	while (list != 0)
	{
		tmp = list;
		list = list->next;
		f(tmp);
	}
}
