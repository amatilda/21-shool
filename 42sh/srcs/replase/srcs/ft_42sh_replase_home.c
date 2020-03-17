/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

size_t			ft_42sh_replase_home_test(register unsigned char *start,
register unsigned char *b)
{
	if (start == b - 1 || b[-2] <= 0x20)
		return (1);
	return (0);
}

static void		*fn_login(register t_main_42sh *array,
register unsigned char **out, register unsigned char *b,
register unsigned char *e)
{
	unsigned char						*start;
	register unsigned char				*dest;
	register size_t						count;
	t_replase_in_42sh					in;

	in.array = array;
	in.b_mode = PARSING_MODE_CMD_42SH;
	start = b;
	if ((count = ft_42sh_replase_count(&in, &start, out, e)) == 0)
		return (0);
	if ((dest = ft_malloc(count + LEN_(EXP_HOME_PATH_42SH) + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(dest, EXP_HOME_PATH_42SH, LEN_(EXP_HOME_PATH_42SH));
	b = dest + LEN_(EXP_HOME_PATH_42SH);
	ft_42sh_replase(&in, b, start, e);
	b[count] = 0;
	count += LEN_(EXP_HOME_PATH_42SH);
	array->count_home_tmp = count;
	return (dest);
}

static size_t	fn_login_faill(register unsigned char **out,
register unsigned char *dest, register unsigned char *b)
{
	*out = b;
	ft_free(dest);
	return (1);
}

size_t			ft_42sh_replase_home_count(register t_main_42sh *array,
register unsigned char **out, register unsigned char *e)
{
	register unsigned char				*b;
	register unsigned char				*tmp;
	register unsigned char				litter;
	register unsigned char				*dest;
	struct stat							st;

	b = *out;
	if (b == e || (b < e && (b[0] <= 0x20 || b[0] == '/' ||
	ft_42sh_parsing_litter_e_f(b, e) == 0)))
		return ((array->lp_home == 0) ? 0 : array->count_home);
	if (b[0] == '~')
		return (1);
	if ((dest = fn_login(array, out, b, e)) == 0)
		return ((array->lp_home == 0) ? 0 : array->count_home);
	tmp = dest;
	while ((litter = tmp[0]) != 0 && litter == '/')
		tmp++;
	tmp[0] = 0;
	if (stat((void *)dest, &st) != 0 || (st.st_mode & S_IFMT) != S_IFDIR)
		return (fn_login_faill(out, dest, b));
	tmp[0] = litter;
	array->lp_home_tmp = dest;
	array->lp_home_tmp_next = *out;
	return (array->count_home_tmp);
}

void			*ft_42sh_replase_home(register t_main_42sh *array,
register unsigned char *dest, register unsigned char **out,
register unsigned char *e)
{
	register size_t						count;
	register unsigned char				*b;

	b = *out;
	if (b == e || (b < e && (b[0] <= 0x20 || b[0] == '/' ||
	ft_42sh_parsing_litter_e_f(b, e) == 0)))
	{
		if ((b = (void *)array->lp_home) == 0)
			return (dest);
		ft_memcpy(dest, b, (count = array->count_home));
		return (dest + count);
	}
	if (b[0] == '~' || (b = array->lp_home_tmp) == 0)
	{
		dest++[0] = '~';
		return (dest);
	}
	ft_memcpy(dest, b, (count = array->count_home_tmp));
	ft_free(b);
	array->lp_home_tmp = 0;
	*out = array->lp_home_tmp_next;
	return (dest + count);
}
