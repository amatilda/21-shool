/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:55:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/05 14:55:45 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (*alst == 0 || del == 0)
		return ;
	list = *alst;
	while (list != 0)
	{
		tmp = list;
		list = list->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = 0;
}
