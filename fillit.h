/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:27:02 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/22 21:34:04 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libftplus/libft.h"
# define	ERROR(msg, r) {ft_putendl(msg); return(r);} 

int		fillit(int fd);
char	*piece_convert(char *tetrimap);
char	*block_test(char *tetrimap, int *i, char *res, int *blockcount);
char	*gnltopiece(char ***gnlread);
int		format_confirm(char *piece);
char	**ft_readfd(int fd, size_t size);
int		format_core(char **gnlread, char **tetrimap, int *count);
char	**make_map(int size);
int		map_start(int count);

#endif
