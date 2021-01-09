/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_list_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

static void		*fn_hash(register t_all_cmd_42sh *list,
register void *str, register size_t b_type)
{
	register void				*tmp;

	if (b_type != 0)
	{
		if ((b_type & AUTO_TYPE_ALIAS_42SH) != 0)
			return (0);
		if ((b_type & AUTO_TYPE_HASH_42SH) != 0)
		{
			tmp = list->path_hash;
			if (ft_strcmp(tmp, str) == 0)
				return (0);
			ft_free(tmp);
		}
		list->count_cmd = 0;
		list->b_type = list->b_type | AUTO_TYPE_HASH_42SH;
		if ((list->path_hash = ft_strdup((void *)str)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		return (0);
	}
	if ((list->path_hash = ft_strdup((void *)str)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	list->b_type = AUTO_TYPE_HASH_42SH;
	return (list);
}

void			*ft_42sh_auto_list_add(register t_main_42sh *array,
register t_all_cmd_42sh *list, register void *str, register size_t b_type)
{
	if (b_type == AUTO_TYPE_EXE_42SH || b_type == AUTO_TYPE_FUN_42SH)
	{
		if (list->b_type != 0)
			return (list);
		list->path = str;
		list->b_type = b_type;
	}
	else if (b_type == AUTO_TYPE_HASH_42SH)
		return (fn_hash(list, str, list->b_type));
	else if (b_type == AUTO_TYPE_ALIAS_42SH)
	{
		if (list->b_type == 0)
			list->b_type = AUTO_TYPE_ALIAS_42SH;
		else
			list->b_type = list->b_type | AUTO_TYPE_ALIAS_42SH;
	}
	return (list);
	(void)array;
}
