/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:16:00 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/10 19:10:24 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_test(char *str, char *to_find)
{
	int		i;

	i = 0;
	while (str[i] != 0 && to_find[i] != 0)
	{
		if (str[i] != to_find[i])
		{
			return (0);
		}
		i++;
	}
	if (str[i] == 0 && to_find[i] != 0)
	{
		return (0);
	}
	return (1);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;

	if (to_find[0] == 0)
	{
		return ((char*)str);
	}
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[0])
		{
			if (ft_test((char*)str + i, (char*)to_find) != 0)
			{
				return ((char*)str + i);
			}
		}
		i++;
	}
	return (0);
}
