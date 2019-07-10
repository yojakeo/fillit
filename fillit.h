/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:27:02 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/09 21:33:34 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libftplus/libft.h"

int		fillit(int fd);
char	*piece_convert(char *tetrimap);
char	*gnltopiece(char **gnlread);
int		format_confirm(char *piece);
char	**ft_readfd(int fd, size_t size);

#endif
