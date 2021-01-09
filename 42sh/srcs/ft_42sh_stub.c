/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_stub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

int			ft_42sh_stub_ioctl(register t_main_42sh *array,
register unsigned long number, register void *lp)
{
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		return (0);
	return (ioctl(FD_TERMINAL_42SH, number, lp));
}
