/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:55:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/05 14:55:45 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;

	if (lst == 0 || f == 0)
		return (0);
	out = f(lst);
	if (out == 0)
		return (0);
	out->next = ft_lstmap(lst->next, f);
	return (out);
}
