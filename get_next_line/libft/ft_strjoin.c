/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:08:06 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 23:08:09 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	count1;
	size_t	count2;

	if (s1 == 0 || s2 == 0)
		return (0);
	count1 = 0;
	count2 = 0;
	while (s1[count1] != 0)
		count1++;
	while (s2[count2] != 0)
		count2++;
	count1 += count2 + 1;
	if (count1 == 0)
		return (0);
	if ((out = malloc(count1)) == 0)
		return (0);
	count1 = 0;
	while (s1[0] != 0)
		out[count1++] = s1++[0];
	while (s2[0] != 0)
		out[count1++] = s2++[0];
	out[count1] = 0;
	return (out);
}
