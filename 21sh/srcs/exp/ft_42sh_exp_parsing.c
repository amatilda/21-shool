/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

unsigned char			*ft_42sh_exp_parsing(register t_past_sort_42sh *root,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register unsigned char			litter;
	register size_t					tempos;
	register t_env_42sh				*list;

	b = *src;
	tmp = b;
	while (b < end && (litter = b[0]) != '/' && litter > 0x20 &&
	litter != '\\' && litter != '"' && litter != '\'' && litter != '$')
		b++;
	if ((tempos = b - tmp) == 0)
		dest++[0] = '$';
	else if ((list = ft_42sh_list_find_key(root, (char *)tmp, tempos)) != 0)
	{
		*src = b;
		ft_memcpy(dest, list->lp_value, (tempos = list->value_count));
		dest += tempos;
		return (dest);
	}
	*src = ft_42sh_parsing_sp(b, end);
	return (dest);
}

size_t					ft_42sh_exp_parsing_count(register t_past_sort_42sh
*root, unsigned char **src, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register unsigned char			litter;
	register size_t					tempos;
	register t_env_42sh				*list;

	if (root->first == 0)
		return (1);
	b = *src;
	tmp = b;
	while (b < end && (litter = b[0]) != '/' && litter > 0x20 &&
	litter != '\\' && litter != '"' && litter != '\'' && litter != '$')
		b++;
	if ((tempos = b - tmp) == 0)
		return (1);
	*src = b;
	if ((list = ft_42sh_list_find_key(root, (char *)tmp, tempos)) != 0)
		return (list->value_count);
	*src = ft_42sh_parsing_sp(b, end);
	return (0);
}
