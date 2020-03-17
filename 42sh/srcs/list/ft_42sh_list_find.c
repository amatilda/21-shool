/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		*ft_42sh_list_find_key(t_past_sort_42sh *root,
register void *key, register size_t n)
{
	register t_std_key_42sh		*center;
	register size_t				count;
	register size_t				tempos;

	if (root->first == 0)
		return (0);
	center = root->center;
	count = center->key_count;
	count = count > n ? n : count;
	if ((tempos = ft_strncmp(center->lp_key, key, count)) > 0 ||
	(tempos == 0 && center->key_count > n))
		center = root->first;
	while (center != 0)
	{
		if (center->key_count == n && ft_strncmp(center->lp_key, key, n) == 0)
			return (center);
		center = center->next;
	}
	return (0);
}
