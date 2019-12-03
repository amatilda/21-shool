/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:08:06 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 23:08:09 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null(void)
{
	char	*out;

	if ((out = malloc(1)) == 0)
		return (0);
	out[0] = 0;
	return (out);
}

static char	*fn_stub(size_t size)
{
	if (size == 0)
		return (0);
	return (malloc(size));
}

char		*ft_strtrim(char const *s)
{
	char	*out;
	char	*start;
	size_t	i;

	if (s == 0)
		return (0);
	while (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		s++;
	if (s[0] == 0)
		return (ft_null());
	start = (char*)s;
	while (s[0] != 0)
		s++;
	s--;
	while (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		s--;
	s++;
	if ((out = fn_stub(s - start + 1)) == 0)
		return (0);
	i = 0;
	while (start != s)
		out[i++] = start++[0];
	out[i] = 0;
	return (out);
}
