/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_echo_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

void		*ft_42sh_cm_echo_number(register t_write_buff *out,
register unsigned char *str, unsigned char **save)
{
	register size_t					n;
	register size_t					number;
	register unsigned char			*tmp;
	register unsigned char			lit;

	tmp = *save;
	ft_write_buffer_str(out, (void *)tmp, str - tmp);
	tmp = ++str + 1;
	n = 0;
	while ((lit = tmp++[0]) != 0 && lit >= 0x30 && lit <= 0x37 && n < 3)
		n++;
	tmp = str + 1;
	str += n;
	*save = str + 1;
	if (n-- == 0)
		return (str);
	number = 0;
	while (n > 0)
		number += (tmp++[0] - 0x30) * (n-- << 3);
	ft_write_buffer_char(out, (unsigned char)(number + (tmp[0] - 0x30)), 1);
	return (str);
}
