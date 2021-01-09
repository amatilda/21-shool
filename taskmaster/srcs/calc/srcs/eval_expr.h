/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:38:28 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"
# include "../includes/ft_42sh_calc_import.h"
# include "eval_expr_export.h"

typedef enum				e_calc_tkntype
{
	CALC_START = 0,
	CALC_ERROR = 1,
	CALC_END = 2,
	CALC_NUMBER = 3,
	CALC_PLUS = 4,
	CALC_MINUS = 5,
	CALC_MUL = 6,
	CALC_DIV = 7,
	CALC_MOD = 8,
	CALC_INC = 9,
	CALC_DEC = 10,
	CALC_LESS = 11,
	CALC_MORE = 12,
	CALC_LESSOREQ = 13,
	CALC_MOREOREQ = 14,
	CALC_EQ = 15,
	CALC_DIFF = 16,
	CALC_AND = 17,
	CALC_OR = 18,
	CALC_VAR = 19,
	CALC_PRE_INC = 20,
	CALC_PRE_DEC = 21,
	CALC_FIR_SC = 22,
	CALC_SEC_SC = 23,
	CALC_REC_ERROR = 24,
	CALC_NUM_OVERFLOW_ERROR = 25
}							t_calc_tkntype;

typedef struct				s_calc_token
{
	t_calc_tkntype			type;
	char					*var;
	struct s_calc_token		*next;
	struct s_calc_token		*prev;
}							t_calc_token;

typedef struct				s_int
{
	int						ol;
	int						zl;
	int						d;
	long long				*stackos;
	long long				*stackzn;
	int						i;
	char					*s;
	t_calc_token			*first_token;
}							t_int;

typedef struct				s_calc
{
	long long				*stackos;
	long long				*stackzn;
	t_int					*str;
	int						*error;
	char					*delstr;
}							t_calc;

int							is_znak(int c);
long long					eval_expr(t_cacl_in *in, char *s, int *error,
char *rec_var);
long long					calcend(t_cacl_in *in, t_int *l,
t_int **str, int *error);
int							prior(int c);
int							ft_atoi_with(char *str, int *marker);
int							is_znak_type(t_calc_tkntype type);
t_int						*cr_new_el(char *s, int *error);
void						*calc(long long *stackos, t_int *str,
							t_calc_tkntype c, char *error_var);
void						addos(long long *stackos, int c, t_int *lastint);
void						subos(long long *stackos, t_int *lastint);
void						addzn(long long *stackzn, t_calc_tkntype c,
								t_int *lastint);
void						subzn(long long *stackzn, t_int *lastint);
int							c_e(t_calc calce);
t_int						*tmp_0(t_int *tmp, char *s);
t_calc_token				*ft_ntoken(char *line,
								t_calc_tkntype type);
char						*calc_ltoa(long long num);
int							is_incr_sym(char c);
int							calc_word_size(char *str, int type);
t_calc_token				*calc_define_token(char *str);
void						*dostack(long long *stackos, long long *stackzn,
								t_calc_token *c, t_int *lastint);
t_calc_token				*add_token_cr(t_calc_token *start,
								t_calc_token *token_to_add);
t_calc_token				*ft_make_token_from_str(char *str, int *i,
								t_calc_token *prev_token);
t_calc_token				*ft_eval_parse(char *str, char *rec_var);
int							issc(char c);
t_calc_token				*define_standart_token(char *str, int *i);
t_calc_token				*check_and_define_pre_incr(char *str, int *i,
								t_calc_token *prev_token);
t_calc_token				*check_calc_error(char *str, int *i,
								t_calc_token *prev_token);
t_calc_token				*check_calc_incr_after(char *str, int *i,
								t_calc_token *prev_token);
t_calc_token				*check_if_incr_with_num(char *str, int *i,
								t_calc_token *prev_token);
t_calc_token				*calc_get_next_tkn(char *str, size_t pos);
t_calc_token				*calc_define_token_next(char *str);
void						free_calc_tokens(t_calc_token *tmp);
int							return_with_error(t_cacl_in *in,
t_calc_token *error_token, int *error, t_int *l);
int							is_znak_type(t_calc_tkntype type);
t_calc_token				*get_last_token(t_calc_token *tmp);
void						zam_var(t_cacl_in *in, t_calc_token *var_token,
int *error);
t_calc_token				*calc_prev_mean_calc_token(t_calc_token *tmp);

int							ft_isdigit(int c);
int							ft_isalpha(int c);
void						*ft_memalloc(size_t size);
char						*ft_strnew(size_t size);
int							ft_str_is_numeric(char *s);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strncpy(char *dst, const char *src, size_t len);
char						*ft_strsub(char const *s, unsigned int start,
size_t len);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_itoa_add(int n);
void						ft_strcat_char(char *buf, char c);
char						*ft_get_next_word(char *str, int i);
int							sc_size(char *str, char b);
void						ft_strdel(char **as);

char						*ft_get_var(char *dop, char **env);

#endif
