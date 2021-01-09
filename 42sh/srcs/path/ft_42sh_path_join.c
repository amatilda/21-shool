/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_path_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_path.h"

char			*ft_42sh_path_join(register char const *s1,
register char const *s2)
{
	register char	*out;
	register size_t	count;
	register size_t	size;

	size = 0;
	while (s1[size] != 0)
		size++;
	count = 0;
	while (s2[count] != 0)
		count++;
	size += count;
	if ((out = ft_malloc(size + 2)) == 0)
		return (0);
	size = (size_t)out;
	while ((count = (unsigned char)s1++[0]) != 0)
		out++[0] = (unsigned char)count;
	out++[0] = '/';
	while ((count = (unsigned char)s2++[0]) != 0)
		out++[0] = (unsigned char)count;
	out[0] = 0;
	return ((char *)size);
}

void			ft_42sh_path_view(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	register unsigned char			*tmp;

	if ((tmp = array->pwd.path_view) != 0)
		ft_free(tmp);
	array->pwd.path_view = ft_42sh_str_shield(b, e, SHIELD_EXTERNALLY,
	&array->pwd.sh_path_view);
}
