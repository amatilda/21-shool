/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:32:19 by qmartina          #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "eval_expr.h"

char	*ft_strsub(char const *s, unsigned int start,
		size_t len)
{
	char	*tmp;
	char	*delstr;

	if (!s || !(tmp = ft_memalloc(len + 1)) || (len + 1) == 0)
		return (NULL);
	delstr = tmp;
	tmp = ft_strncpy(tmp, (char*)s + start, len);
	if (tmp == NULL)
	{
		ft_strdel(&delstr);
		return (NULL);
	}
	return (tmp);
}
