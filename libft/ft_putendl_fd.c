/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:30:09 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/05 13:30:11 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		count;

	if (s != 0)
	{
		count = 0;
		while (s[count] != 0)
			count++;
		write(fd, s, count);
	}
	write(fd, "\n", 1);
}
