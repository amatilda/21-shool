/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_hrdc_add.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

size_t		ft_42sh_replase_hrdc_test_dq(unsigned char **out,
register unsigned char *e)
{
	register unsigned char	lit;

	lit = 0x20;
	while ((lit = ft_42sh_parsing_test_next(out, e, 0, lit)) != 0 &&
	lit != '\'' && lit != '"')
		if (lit == '\\')
			ft_42sh_replase_slesh_count(out, e);
	return (lit);
}
