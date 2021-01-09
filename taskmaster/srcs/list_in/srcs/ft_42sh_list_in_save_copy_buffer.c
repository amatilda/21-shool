/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_save_copy_buffer.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_list_in.h"

static uint8_t		*fn_copy_split(uint8_t *b, register t_slesh_42sh **array)
{
	t_slesh_42sh		*slesh;

	while ((slesh = array++[0]) != 0)
		b = ft_memcpy(b, slesh, sizeof(t_slesh_42sh)) + sizeof(t_slesh_42sh);
	return (b);
}

void				ft_42sh_list_in_save_crypto(register uint8_t *b,
register size_t len)
{
	register uint8_t			*e;

	b = b + sizeof(t_in_save_42sh);
	e = b + (len - sizeof(t_in_save_42sh));
	while (b < e)
	{
		b[0] = b[0] ^ (uint8_t)CRYPTO_FC_SAVE_XOR_42SH;
		b++;
	}
}

static void			fn_set(t_in_save_42sh *b, register t_main_42sh *array)
{
	register size_t			crc32;

	b->version = VERSION_LIST_42SH;
	b->crc32 = 0;
	crc32 = ft_crc32_mirror_one(array->lp_crc32_mirror, b, b->len,
	CRC32_START_MIRROR_42SH);
	b->crc32 = crc32;
	ft_42sh_list_in_save_crypto((uint8_t *)b, b->len);
}

void				ft_42sh_list_in_save_copy_buffer(uint8_t *b,
register t_in_42sh *list, register t_main_42sh *array)
{
	register t_slesh_42sh	**tmp_slesh;
	register size_t			tempos;
	register t_in_42sh		*tmp;
	register t_in_save_42sh	*save;

	save = (t_in_save_42sh *)b;
	b = b + sizeof(t_in_save_42sh);
	while (list != 0)
	{
		list->lp_current = (char *)(list->lp_current - list->lp_b);
		b = ft_memcpy(b, list, sizeof(t_in_42sh)) + sizeof(t_in_42sh);
		b = ft_memcpy(b, list->lp_b, list->count) + list->max;
		if ((tmp_slesh = list->spl_slesh) != 0)
			b = fn_copy_split(b, tmp_slesh);
		if ((tempos = list->max_dup) != 0)
		{
			b = ft_memcpy(b, list->lp_b_dup, list->count_dup) + tempos;
			if ((tmp_slesh = list->spl_slesh_dup) != 0)
				b = fn_copy_split(b, tmp_slesh);
		}
		tmp = list;
		list = list->next;
		ft_42sh_list_in_free(tmp);
	}
	fn_set(save, array);
}
