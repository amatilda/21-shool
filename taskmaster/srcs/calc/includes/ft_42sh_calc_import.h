/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_calc_import.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by amatilda          #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_CALC_IMPORT_H
# define FT_42SH_CALC_IMPORT_H

# define CALC_MODE_ENV_GET			0x1
# define CALC_MODE_ENV_SET			0x2

typedef struct				s_cacl_in
{
	void					*array;
	uint8_t					b_test;
	void					*lp_error;
}							t_cacl_in;

void						*ft_42sh_calc_get_env(register void *array,
register void *b);
void						ft_42sh_calc_set_env(register void *array,
register void *b, register size_t number);
void						*ft_42sh_calc_error_pre(register char *s1,
register char *s2, register char *s3);
#endif
