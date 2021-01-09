/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:30:48 by pro               #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "eval_expr.h"

void		ft_strcat_char(char *buf, char c)
{
	char	*dopstr;

	dopstr = ft_strdup(" ");
	dopstr[0] = c;
	ft_strcat((char *)buf, dopstr);
	ft_strdel(&dopstr);
}
