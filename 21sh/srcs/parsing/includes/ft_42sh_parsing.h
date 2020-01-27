/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_PARSING_H
# define FT_42SH_PARSING_H

# include "ft_42sh.h"

typedef struct			s_parsing_in_42sh
{
	t_string			cmd;
	char				**lp_arg;
}						t_parsing_in_42sh;

void					ft_42sh_parsing_while(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, register unsigned char *end);
t_jobs_42sh				*ft_42sh_parsing_while_availability(
register t_main_42sh *array, register t_parsing_in_42sh *in, unsigned char *b,
register unsigned char *end);

#endif
