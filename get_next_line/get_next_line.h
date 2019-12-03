/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:05:00 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/08 21:05:02 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE		1

typedef struct		s_get_next_line
{
	char			*lp_cmp;
	char			*lp_prev;
	char			*line;
	size_t			line_count;
	size_t			interval;
	size_t			tmp;
	ssize_t			count;
	char			buffer[BUFF_SIZE];
}					t_get_next_line;

int					get_next_line(const int fd, char **line);

#endif
