/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/20 21:50:12 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

# define BUFF_SIZE 	6400

typedef struct		s_fillit
{
	int				fd;
	char			in[BUFF_SIZE];
	char			x_y[8 * 26];
	char			*alphabet;
	size_t			tettrin_c;
	size_t			contact_c;
	size_t			tettrin_c_tmp;
	size_t			tmp;
	size_t			sqrt_i;
	ssize_t			in_r;
	ssize_t			sqr_line;
	int_fast8_t		x_2;
	int_fast8_t		x_3;
	int_fast8_t		x_4;
	int_fast8_t		y_2;
	int_fast8_t		y_3;
	int_fast8_t		y_4;
}					t_fillit;

int					fn_bruteforce(register t_fillit *fill,
	register uint_fast8_t i, register int_fast8_t x_i,
	register int_fast8_t y_i);
int					fn_validate(register t_fillit *fill, register char *lp_in);

#endif
