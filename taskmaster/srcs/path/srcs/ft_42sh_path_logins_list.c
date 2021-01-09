/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_path_logins_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_path.h"

t_logins_42sh	*ft_42sh_path_logins_list_create(register unsigned char *name,
register size_t name_count, register unsigned char *home_dir,
register size_t home_dir_count)
{
	register t_logins_42sh				*list;
	register unsigned char				*tmp;

	if ((list = ft_malloc(sizeof(t_logins_42sh) +
	name_count + home_dir_count + 2)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	tmp = (void *)list + sizeof(t_logins_42sh);
	list->std.lp_key = (void *)tmp;
	list->std.key_count = name_count;
	list->std.key_litter = 0;
	ft_memcpy(tmp, name, name_count);
	tmp[name_count] = 0;
	tmp += name_count + 1;
	list->home_dir = tmp;
	list->home_dir_count = home_dir_count;
	ft_memcpy(tmp, home_dir, home_dir_count);
	tmp[home_dir_count] = 0;
	list->std.next = 0;
	list->std.prev = 0;
	return (list);
}

void			ft_42sh_path_logins_list_add(register t_main_42sh *array,
register t_logins_42sh *list)
{
	if (array->login.first == 0)
	{
		array->login.first = list;
		array->login.center = list;
		array->login.last = list;
		return ;
	}
	ft_42sh_list_sort_paste(&array->login, &list->std, ft_free);
}

void			ft_42sh_path_logins_list_free(register t_main_42sh *array)
{
	register t_logins_42sh			*list;
	register t_logins_42sh			*tmp;

	list = array->login.first;
	while (list != 0)
	{
		tmp = list;
		list = (void *)list->std.next;
		ft_free(tmp);
	}
	array->login.first = 0;
}

void			ft_42sh_path_logins_test_empty(register t_main_42sh *array)
{
	register t_logins_42sh				*list;

	if (array->login.first != 0)
		return ;
	list = ft_42sh_path_logins_list_create((void *)"root", 4,
	(void *)"/var/root", 9);
	ft_42sh_path_logins_list_add(array, list);
}
