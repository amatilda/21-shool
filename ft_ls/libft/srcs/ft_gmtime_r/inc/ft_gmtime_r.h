/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gmtime_r.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GMTIME_R_H
# define FT_GMTIME_R_H

# include "libft.h"

typedef struct		s_gmtime_r
{
	size_t			big;
	size_t			common;
	time_t			unix_time;
	struct tm		*result;
	int_fast32_t	bisextos;
}					t_gmtime_r;

#endif
