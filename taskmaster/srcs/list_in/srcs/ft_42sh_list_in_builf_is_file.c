/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_builf_is_file.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_list_in.h"
#include <stdbool.h>

static t_in_42sh	*fn_faill(t_in_42sh *list, void *lp_b,
t_slesh_42sh **spl_slesh, void *lp_b_dup)
{
	if (list != 0)
		ft_free(list);
	if (lp_b != 0)
		ft_free(lp_b);
	if (spl_slesh != 0)
		ft_strsplit_free((char **)spl_slesh);
	if (lp_b_dup != 0)
		ft_free(lp_b_dup);
	return (0);
}

static uint8_t		*fn_build_list_dup(t_in_42sh *list, uint8_t *b)
{
	if (list->max_dup != 0)
	{
		if ((list->lp_b_dup = malloc(list->max_dup)) == 0)
			return ((uint8_t *)fn_faill(list, list->lp_b, list->spl_slesh, 0));
		ft_memcpy(list->lp_b_dup, b, list->count_dup);
		b += list->max_dup;
		if (list->spl_slesh_dup != 0)
		{
			if ((list->spl_slesh_dup = ft_42sh_list_in_builf_slesh(&b,
			list->slesh_max_dup + 1)) == 0)
			{
				return ((uint8_t *)fn_faill(list, list->lp_b, list->spl_slesh,
				list->lp_b_dup));
			}
		}
	}
	return (b);
}

static t_in_42sh	*fn_build_list(uint8_t **buffer)
{
	uint8_t						*b;
	t_in_42sh					*list;

	b = *buffer;
	if ((list = malloc(sizeof(t_in_42sh))) == 0)
		return (0);
	ft_memcpy(list, b, sizeof(t_in_42sh));
	b = b + sizeof(t_in_42sh);
	if ((list->lp_b = malloc(list->max)) == 0)
		return (fn_faill(list, 0, 0, 0));
	list->lp_current = (size_t)list->lp_current + list->lp_b;
	ft_memcpy(list->lp_b, b, list->count);
	b += list->max;
	if (list->spl_slesh != 0)
	{
		if ((list->spl_slesh = ft_42sh_list_in_builf_slesh(&b,
		list->slesh_max + 1)) == 0)
		{
			return (fn_faill(list, list->lp_b, 0, 0));
		}
	}
	if ((b = fn_build_list_dup(list, b)) == 0)
		return (0);
	*buffer = b;
	return (list);
}

size_t				ft_42sh_list_in_builf_is_file(register t_main_42sh *array,
uint8_t *b, register uint8_t *e)
{
	t_in_42sh					*list;
	t_in_42sh					*list_tmp;

	if ((list = fn_build_list(&b)) == 0)
		return (false);
	list->next = 0;
	list->prev = 0;
	array->in.in_first = list;
	while (b < e)
	{
		if ((list_tmp = fn_build_list(&b)) == 0)
			break ;
		list->next = list_tmp;
		list_tmp->prev = list;
		list_tmp->next = 0;
		list = list_tmp;
	}
	array->in.in_current = list;
	array->in.in_last = list;
	return (true);
}