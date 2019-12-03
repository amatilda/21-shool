/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/09 16:20:21 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <time.h>
# include <wchar.h>
# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_itoa.h"
# include "ft_lnbr.h"
# include "ft_printf.h"
# include "ft_gmtime_r.h"
# include "fn_str_time.h"

/*
** ft_printf defines
*/
# define PRT_RESET		"\x1b[0m"
# define PRT_RED		"\x1b[31m"
# define PRT_GREEN		"\x1b[32m"
# define PRT_YELLOW		"\x1b[33m"
# define PRT_BLUE		"\x1b[34m"
# define PRT_PURPLE		"\x1b[35m"
# define PRT_LIGHT_BLUE	"\x1b[36m"
# define PRT_WHITE		"\x1b[37m"

/*
** ft_itoa defines
*/
# define ITOA_LOWER  	0x0
# define ITOA_UPPER  	0x1
# define ITOA_SIGNED 	0x2
# define ITOA_GROUPED 	0x4
# define ITOA_PLUS 		0x8
# define ITOA_NOT_ONE	0x10
# define ITOA_UP_ABC	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ITOA_LOW_ABC	"0123456789abcdefghijklmnopqrstuvwxyz"

/*
** Standart libft functions
*/

int			ft_strcmp(const char *s1, const char *s2);
int			ft_printf(const char *format, ...);
int			ft_snprintf(char *str, size_t size, const char *format, ...);
int			ft_atoi(const char *str);
int			ft_itoa(char *buffer, uintmax_t value,
				uint_fast8_t base, uint_fast8_t b_up);
int			ft_wctomb(char *s, wchar_t wchar);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dest, const char *src);
void		*ft_memset(void *b, int c, size_t len);

size_t		ft_strlen(const char *s);
size_t		ft_wcslen(const wchar_t *s);
struct tm	*ft_gmtime_r(const time_t *clock, struct tm *result);

#endif
