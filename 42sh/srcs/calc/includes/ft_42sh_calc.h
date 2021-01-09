/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_calc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by amatilda          #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_CALC_H
# define FT_42SH_CALC_H

# include "ft_42sh.h"
# include "ft_42sh_calc_import.h"
# include "../srcs/eval_expr_export.h"

unsigned char		*ft_42sh_calc_end(register unsigned char *b,
register unsigned char *e);
unsigned char		ft_42sh_dq_test_err_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n);

#endif
