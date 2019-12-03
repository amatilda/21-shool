/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:08:59 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/05 14:09:03 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	size_t		i;

	content_size = (content == 0) ? 0 : content_size;
	if ((list = malloc(sizeof(t_list))) == 0)
		return (0);
	list->content_size = content_size;
	list->next = 0;
	if (list->content_size == 0)
		list->content = 0;
	else
	{
		if ((list->content = malloc(list->content_size)) == 0)
		{
			free(list);
			return (0);
		}
		i = 0;
		while (i < list->content_size)
		{
			*((char*)list->content + i) = *((char*)content + i);
			i++;
		}
	}
	return (list);
}
