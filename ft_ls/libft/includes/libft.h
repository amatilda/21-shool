/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/07 19:01:15 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stddef.h>
# include <time.h>

# define ITOA_LOWER  	0x0
# define ITOA_UPPER  	0x1
# define ITOA_SIGNED 	0x2
# define ITOA_GROUPED 	0x4
# define ITOA_PLUS 		0x8
# define ITOA_NOT_ONE	0x10

int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
size_t		ft_wcslen(const wchar_t *s);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
int			ft_itoa(char *buffer, uintmax_t value,
		uint_fast8_t base, uint_fast8_t b_up);
int			ft_wctomb(char *s, wchar_t wchar);
struct tm	*ft_gmtime_r(const time_t *clock, struct tm *result);

#endif
