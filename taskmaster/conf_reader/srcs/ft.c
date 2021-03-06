/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:29:31 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:40:06 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include "conf.h"

void					*my_malloc(size_t size)
{
	char				*ret;
	size_t				i;

	if (!(ret = (char*)malloc(size)))
		ft_crash("Malloc error");
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return ((void*)ret);
}

int						my_atoi(const char *str)
{
	size_t				i;
	unsigned long long	result;
	int					sign;

	result = 0;
	i = 0;
	sign = 0;
	if (str[i] < '0' || str[i] > '9')
	{
		if (str[i] == '-')
			sign = 1;
		else if (str[i] != '+')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > INT_MAX)
			return (-2);
		result = (result * 10) + (str[i++] - '0');
	}
	if (str[i])
		return (-1);
	return (sign == 1 ? -result : result);
}

int						str_is_empty(const char *str)
{
	register size_t		i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
			return (str[i] == '#');
		i++;
	}
	return (1);
}

char					*my_strjoin(char const *s1, char const *s2, int to_free)
{
	char				*str;
	register size_t		i;
	register size_t		k;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(strlen((char*)s1) + strlen((char*)s2) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i])
		str[k++] = s1[i++];
	i = 0;
	while (s2[i])
		str[k++] = s2[i++];
	str[k] = '\0';
	(to_free == 1) ? free((void*)s1) : 0;
	(to_free == 2) ? free((void*)s2) : 0;
	if (to_free == 3)
	{
		free((void*)s1);
		free((void*)s2);
	}
	return (str);
}

void					ft_crash(const char *msg, ...)
{
	va_list				args;

	dprintf(fd().e, TASK_ERROR_COLOR);
	va_start(args, msg);
	vdprintf(fd().e, msg, args);
	va_end(args);
	dprintf(fd().e, "\n"TASK_RESET);
	exit(msg ? msg[0] : 127);
}
