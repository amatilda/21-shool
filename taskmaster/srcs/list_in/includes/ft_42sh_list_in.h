/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_LIST_IN_H
# define FT_42SH_LIST_IN_H

# include "ft_42sh.h"

# define CRYPTO_FC_SAVE_XOR_42SH		0x44

typedef struct				s_in_save_42sh
{
	size_t					crc32;
	size_t					len;
	size_t					version;
	size_t					i;
}							t_in_save_42sh;

void						ft_42sh_list_in_save_copy_buffer(uint8_t *b,
register t_in_42sh *list, register t_main_42sh *array);
void						ft_42sh_list_in_save_file(t_in_save_42sh *b);
char						*ft_42sh_list_in_save_get_path(void);
void						ft_42sh_list_in_save_crypto(register uint8_t *b,
register size_t len);
size_t						ft_42sh_list_in_builf_is_file(register
t_main_42sh *array, uint8_t *b, register uint8_t *e);
t_slesh_42sh				**ft_42sh_list_in_builf_slesh(uint8_t **buffer,
size_t count);

#endif
