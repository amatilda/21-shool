/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/06 12:13:43 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define F_UP_ABC	"0123456789ABCDEF"
# define F_LOW_ABC	"0123456789abcdef"

# define SIZE_B 0x4000
# define STR_SUB "hljtzL"
# define STR_FORMAT "sSpPdDioOuUxXcCnbBkfFeEaAr"
# define STR_TIME_STANDART	0x0

# define PRINTF_P			ITOA_LOWER | ITOA_SIGNED | ITOA_PLUS
# define PRINTF_E			ITOA_LOWER | ITOA_SIGNED | ITOA_PLUS | ITOA_NOT_ONE
# define PRINTF_MLT_DEC 	1000000000
# define PRINTF_MLT_DEC_C	9
# define PRINTF_SIZE_ROUND	19

typedef struct				s_float
{
	union					u_val_stub
	{
		long double			value;
		struct				s_mantiss_stub
		{
			uint64_t		mantissa;
			uint16_t		exponent;
		}					t_mant;
	}						t_val;
	char					str[10];
	char					buffer[3];
	char					letter_max;
	char					letter_tmp;
	char					letter_tmp2;
	char					*first;
	char					*end;
	char					*end_tmp;
	char					*start;
	char					*alphabet;
	size_t					min;
	int16_t					e_save;
	uint64_t				float_sing;
	uint64_t				float_fract;
	uint_fast8_t			up;
	uint_fast8_t			change;
	uint_fast16_t			float_sing_e;
	uint_fast16_t			float_fract_e;
}							t_float;

typedef struct				s_option
{
	char					letter;
	size_t					min;
	size_t					max;
	intmax_t				e;
	uint_fast8_t			base;
	uint_fast8_t			b_ox;
	uint_fast8_t			count;
	uint_fast8_t			minus;
	uint_fast8_t			b_exp;
	uint_fast8_t			b_max;
	uint_fast8_t			b_plus;
	uint_fast8_t			b_grup;
	uint_fast8_t			b_left;
	uint_fast8_t			b_null;
	uint_fast8_t			b_space;
	uint_fast8_t			b_round;
	uint_fast8_t			b_prefix;
	uint_fast8_t			b_max_over;
	uint_fast8_t			b_max_over_str;
	uint_fast8_t			b_sub[sizeof(STR_SUB) + 2];
	uint_fast16_t			grup;
	uint_fast16_t			sing;
}							t_option;

typedef struct				s_arg
{
	char					*b;
	size_t					size_b;
	size_t					fildes;
	va_list					ap;
	const char				*f;
	uint_fast8_t			b_in_str;
}							t_arg;

typedef struct				s_static
{
	int						(*fn[sizeof(STR_FORMAT)])();
	char					*str_format;
	char					*str_sub;
	char					*str_not[0x1F + 2];
}							t_static;

typedef struct				s_my
{
	char					*b;
	char					*str_tmp_sub;
	char					buffer[SIZE_B];
	size_t					arg;
	size_t					out;
	size_t					tmp;
	size_t					count;
	size_t					size_b;
	size_t					fildes;
	size_t					end_count;
	va_list					ap;
	va_list					ap_n;
	va_list					ap_line;
	t_float					flt;
	t_option				opt;
	t_static				*stc;
	uintmax_t				arg_itoa;
	const char				*f;
	uint_fast8_t			sp;
	uint_fast8_t			null;
	uint_fast8_t			b_star;
	uint_fast8_t			format;
	uint_fast8_t			b_point;
	uint_fast8_t			b_in_str;
}							t_my;

typedef struct				s_ft_str_time_in_out
{
	char *restrict			s;
	const char *restrict	f;
	struct tm				timeptr;
	size_t					opt;
	size_t					max;
	size_t					count_out;
}							t_ft_str_time_in_out;

int							fn_display(register t_my *my);
int							fn_display_float(t_my *my);
int							fn_display_s(register t_my *my);
int							fn_display_p(register t_my *my);
int							fn_display_d(register t_my *my);
int							fn_display_o(register t_my *my);
int							fn_display_u(register t_my *my);
int							fn_display_x(register t_my *my);
int							fn_display_c(register t_my *my);
int							fn_display_n(register t_my *my);
int							fn_display_b(register t_my *my);
int							fn_display_k(register t_my *my);
int							fn_display_f(register t_my *my);
int							fn_display_e(register t_my *my);
int							fn_display_a(register t_my *my);
int							fn_display_r(register t_my *my);
int							fn_display_add(register t_my *my);
int							fn_display_float(register t_my *my);
int							fn_display_unknown(register t_my *my);

int							fn_stub_finish_00(register t_my *my,
								register char *buffer,
								register size_t count);
int							fn_str_time(register t_ft_str_time_in_out *in_out);
int							fn_stub_finish(register t_my *my);
void						fn_stub_signed(register t_my *my);
void						fn_sp(register t_my *my, register uint_fast8_t sp);
void						fn_str_copy(register t_my *my,
								register const char *str,
								register size_t count);
void						fn_write_float(register t_my *my);
size_t						fn_big(register t_arg *arg);
size_t						fn_stub_count(register t_my *my,
								register size_t count);

#endif
