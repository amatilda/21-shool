/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp_check_fill.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:08:14 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:08:21 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

static size_t	ft_42sh_auto_comp_test_dir(register char *str,
struct stat *st, register t_main_42sh *array)
{
	array->pguitar.comp.open_dirr = str;
	if (lstat(str, st) == -1)
		return (0);
	if (S_ISDIR((st->st_mode)))
		return (1);
	return (0);
}

static size_t	ft_42sh_auto_comp_is_dir(register char *dir,
register size_t len, register t_main_42sh *array)
{
	size_t			i;
	size_t			j;
	struct stat		st;
	register char	*str;

	i = -1;
	j = 0;
	if (array->pguitar.comp.open_dirr != NULL)
	{
		free(array->pguitar.comp.open_dirr);
		array->pguitar.comp.open_dirr = NULL;
	}
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	while (++i < len)
	{
		if (dir[i] != '\\')
			str[j++] = dir[i];
		else if (dir[i] == '\\' && (dir[i + 1] == '\\'))
			str[j++] = dir[i++];
	}
	str[j] = '\0';
	return (ft_42sh_auto_comp_test_dir(str, &st, array));
}

static size_t	ft_42sh_auto_comp_fill_dir(register t_main_42sh *array,
char *tmp, size_t i)
{
	register size_t	j;
	register size_t	k;
	register char	*str;

	j = -1;
	k = 0;
	str = array->pguitar.comp.str;
	if (!(tmp = (char *)malloc(sizeof(char) *
		(array->pguitar.comp.count_dirr + i + 2))))
		ft_42sh_exit(E_MEM_CODE_42SH);
	while (++j < array->pguitar.comp.count_dirr && i--)
		*(tmp + j) = *(array->pguitar.comp.dirr + j);
	while (k++ < i)
	{
		*(tmp + j) = *str;
		str++;
		j++;
	}
	*(tmp + j) = '/';
	*(tmp + j + 1) = '\0';
	if (ft_42sh_auto_comp_is_dir(tmp, j + 1, array))
		ft_42sh_auto_comp_fill_exist_dir(array, tmp, i);
	else if (ft_42sh_auto_comp_free_not_exist_dir(array, tmp))
		return (0);
	return (1);
}

static size_t	ft_42sh_auto_comp_check_dir_init(register t_main_42sh *array,
register char **tmp, register char **str, register size_t *len)
{
	*tmp = NULL;
	*str = array->pguitar.comp.str;
	*len = array->pguitar.comp.count_str;
	return (0);
}

size_t			ft_42sh_auto_comp_check_dir(register t_main_42sh *array)
{
	size_t	i;
	size_t	len;
	char	*tmp;
	char	*str;

	i = ft_42sh_auto_comp_check_dir_init(array, &tmp, &str, &len);
	while (*str && len != 0)
	{
		if (ft_42sh_auto_comp_is_dir(array->pguitar.comp.dirr,
			array->pguitar.comp.count_dirr, array))
		{
			while (*str != '\0' && *str != '/' && ++i)
				str++;
			if (*str == '/')
			{
				if (!ft_42sh_auto_comp_fill_dir(array, tmp,
					i + array->pguitar.comp.count_dirr))
					return (0);
				str++;
				i = 0;
			}
		}
	}
	return (1);
}
