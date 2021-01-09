/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_log_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:22:01 by wstygg            #+#    #+#             */
/*   Updated: 2020/08/04 18:22:32 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static t_log		*log(t_log *l)
{
	static t_log	ret;

	if (l)
		ret = *l;
	return (&ret);
}

t_log				*get_log(void)
{
	return (log(NULL));
}
