/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:04:08 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:04:08 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

void		ft_free_split(char **split)
{
	int		i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int			ft_split_size(char **split)
{
	int		ret;

	ret = 0;
	while (split[ret])
		ret++;
	return (ret);
}

int			ft_count_words(char *str)
{
	int		in_word;
	int		count;

	in_word = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int			ft_word_length(const char *str, int i)
{
	int		length;

	length = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

char		**ft_splitstr(char *str)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	words = my_malloc(sizeof(char *) * (ft_count_words(str) + 1));
	while (str[i] != '\0' && j < ft_count_words(str))
	{
		k = 0;
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		words[j] = my_malloc(sizeof(char) * ft_word_length(str, i) + 1);
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
			&& str[i] != '\0')
		{
			words[j][k++] = str[i++];
		}
		words[j][k] = '\0';
		j++;
	}
	words[j] = 0;
	return (words);
}
