/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:49:52 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/11 21:02:21 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, const char *src, int nb)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (dest[x] != 0)
	{
		x++;
	}
	while (src[y] != 0 && y < nb)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = 0;
	return (dest);
}
