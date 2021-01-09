/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:36:13 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:36:13 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"

static t_fd		*get_fd(void)
{
	static t_fd	fd = (t_fd){.o = 1, .e = 2};

	return (&fd);
}

void			set_fd_out(const int out)
{
	get_fd()->o = out;
}

void			set_fd_err(const int err)
{
	get_fd()->e = err;
}

t_fd			fd(void)
{
	return (*get_fd());
}
