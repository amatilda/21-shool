/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_builf_slesh.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_list_in.h"
#include <stdbool.h>

static t_slesh_42sh	**fn_fail_slesh(t_slesh_42sh **slesh_save,
t_slesh_42sh **slesh)
{
	t_slesh_42sh				**slesh_tmp;

	slesh_tmp = slesh_save;
	while (slesh_save < slesh)
		ft_free(slesh_save++[0]);
	ft_free(slesh_tmp);
	return (0);
}

t_slesh_42sh		**ft_42sh_list_in_builf_slesh(uint8_t **buffer,
size_t count)
{
	uint8_t						*b;
	t_slesh_42sh				*slesh_tmp;
	t_slesh_42sh				**slesh;
	t_slesh_42sh				**slesh_save;

	if ((slesh = malloc((count + 1) * sizeof(t_slesh_42sh *))) == 0)
		return (0);
	b = *buffer;
	slesh_save = slesh;
	slesh_save[count] = 0;
	while (count-- != 0)
	{
		if ((slesh_tmp = malloc(sizeof(t_slesh_42sh))) == 0)
			return (fn_fail_slesh(slesh_save, slesh));
		ft_memcpy(slesh_tmp, b, sizeof(t_slesh_42sh));
		b += sizeof(t_slesh_42sh);
		slesh++[0] = slesh_tmp;
	}
	*buffer = b;
	return (slesh_save);
}
