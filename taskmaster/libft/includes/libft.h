/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <time.h>

# define PRTF_RESET			"\x1b[0m"

# define PRTF_BOLT			"\x1b[1m"
# define PRTF_INVERT		"\x1b[7m"

# define PRTF_BLACK			"\x1b[30m"
# define PRTF_BLACK_FON		"\x1b[40m"
# define PRTF_RED			"\x1b[31m"
# define PRTF_GREEN			"\x1b[32m"
# define PRTF_YELLOW		"\x1b[33m"
# define PRTF_BLUE			"\x1b[34m"
# define PRTF_PURPLE		"\x1b[35m"
# define PRTF_LIGHT_BLUE	"\x1b[36m"
# define PRTF_WHITE			"\x1b[37m"
# define PRTF_WHITE_FON		"\x1b[47m"

# define ITOA_LOWER			0x0
# define ITOA_UPPER			0x1
# define ITOA_SIGNED		0x2
# define ITOA_GROUPED		0x4
# define ITOA_PLUS			0x8
# define ITOA_NOT_ONE		0x10

# define STR_UTF8_RIGHT		0x0
# define STR_UTF8_LEFT		0x1

typedef struct			s_string
{
	size_t				len;
	size_t				max_len;
	char				*buff;
}						t_string;

typedef struct			s_write_buff
{
	char				*b;
	size_t				max;
	size_t				count;
	int					fd;
}						t_write_buff;

void					*ft_malloc(register size_t n);
void					ft_free(register void *buff);

void					ft_crc32_tabl_mirror(register uint32_t *lp,
uint_fast8_t count_table, register uint32_t polinom);
uint32_t				ft_crc32_mirror_one(register uint32_t *lp,
register void *src, size_t count, register uint32_t crc32);

size_t					ft_unicode_alpha(register uint32_t unicode);
uintmax_t				ft_utf8_decode(register const unsigned char *b);
size_t					ft_strlen_utf8(register const char *s);
size_t					ft_strlen_utf8_n(register const char *s,
register const char *e);
size_t					ft_strlen_utf8_litter(register void *s);

void					ft_write_buffer_char(register t_write_buff *array,
register const char litter, register size_t n);
void					ft_write_buffer_str(register t_write_buff *array,
register const char *str, register size_t n);
void					ft_write_buffer_str_zero(register t_write_buff *array,
register const char *str);
void					ft_write_buffer(register t_write_buff *array);

char					**ft_strsplit(register char const *s, register char c);
void					ft_strsplit_free(register char **array);

char					*ft_strjoin(char const *s1, char const *s2);
void					*ft_strnjoin(register const void *s1,
register size_t n1, register const void *s2, register size_t n2);

int						ft_strcmp(register char *s1, register char *s2);
int						ft_strncmp(register void *s1, register void *s2,
register size_t n);
size_t					ft_strlen(register const char *s);
size_t					ft_wcslen(const wchar_t *s);
void					*ft_strdup(const char *s1);
void					*ft_strndup(const char *s1, size_t n);
char					*ft_strchr(const char *s, int c);
void					*ft_memset(register void *b, register int c,
size_t len);
void					*ft_memcpy(register void *dst, register const void *src,
size_t n);
int						ft_atoi(const char *str);
int						ft_itoa(char *buffer, uintmax_t value,
uint_fast8_t base, uint_fast8_t b_up);
int						ft_wctomb(char *s, wchar_t wchar);
struct tm				*ft_gmtime_r(const time_t *clock, struct tm *result);

#endif
