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

void					ft_42sh_parsing_while(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, register unsigned char *e);
size_t					ft_42sh_parsing_while_availability(
register t_main_42sh *array, register t_jobs_42sh *jobs, unsigned char *b,
size_t n);
unsigned char			*ft_42sh_parsing_while_logic(
register t_main_42sh *array, register unsigned char *b,
register unsigned char *e);
void					ft_42sh_parsing_while_error(register
t_main_42sh *array, register t_jobs_42sh *jobs, unsigned char **out,
register unsigned char *e);
void					*ft_42sh_parsing_cmd_ret(register t_replase_in_42sh
*in, unsigned char **out, register t_exp_set_42sh *exp_set,
register size_t count);
void					*ft_42sh_parsing_exp_set_next(register
t_replase_in_42sh *in, register t_jobs_42sh *jobs,
unsigned char **out, register unsigned char *e);

#endif
