/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:08:38 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:08:42 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

void	ft_42sh_auto_comp_free_strdup(register t_main_42sh *array)
{
	if (array->pguitar.comp.str_dup != NULL)
	{
		free(array->pguitar.comp.str_dup);
		array->pguitar.comp.str_dup = NULL;
	}
}

void	ft_42sh_auto_comp_fill_exist_dir(register t_main_42sh *array,
char *tmp, size_t i)
{
	free(array->pguitar.comp.dirr);
	array->pguitar.comp.dirr = tmp;
	array->pguitar.comp.str += i + 1;
	array->pguitar.comp.count_str -= i + 1;
	array->pguitar.comp.count_dirr += i + 1;
}

size_t	ft_42sh_auto_comp_free_not_exist_dir(register t_main_42sh *array,
char *tmp)
{
	free(tmp);
	tmp = NULL;
	if (array->pguitar.comp.dirr != NULL)
	{
		free(array->pguitar.comp.dirr);
		array->pguitar.comp.dirr = NULL;
	}
	if (array->pguitar.comp.str_dup != NULL)
	{
		free(array->pguitar.comp.str_dup);
		array->pguitar.comp.str_dup = NULL;
	}
	return (1);
}

void	ft_42sh_auto_comp_free_struct(register t_main_42sh *array)
{
	if (array->pguitar.comp.open_dirr != NULL)
	{
		free(array->pguitar.comp.open_dirr);
		array->pguitar.comp.open_dirr = NULL;
	}
	if (array->pguitar.comp.dirr != NULL)
	{
		free(array->pguitar.comp.dirr);
		array->pguitar.comp.dirr = NULL;
	}
	if (array->pguitar.comp.str_dup != NULL)
	{
		free(array->pguitar.comp.str_dup);
		array->pguitar.comp.str_dup = NULL;
	}
}
