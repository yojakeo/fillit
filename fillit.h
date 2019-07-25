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

/*
**	Cores
*/
int		format_core(char **gnlread, char **tetrimap, int *count);
int		solve_core(char **tetrimap, char ***map, int count);
/*
**	Format
*/
char	*gnltopiece(char ***gnlread);
int		format_confirm(char *piece);
/*
**	Converting
*/
char	*piece_convert(char *tetrimap);
char	*block_test(char *tetrimap, char *res, int *i, int *blockcount);
char	*check_backtrack(char *tetrimap, char *res, int *i, int *blockcount);
/*
**	Solving
*/
int		check_overlap(char **map, int x, int y);
int 	check_inbounds(char **map, int x, int y);
char	**insert_pieces(char **tetrimap, char ***map);
/*
**	Reading
*/
char	**ft_readfd(int fd, size_t size);
/*
**	Map Making
*/
int		map_start(int count);
char	**make_map(int size);
/*
**	Fillit Main
*/
int		fillit(int fd);
#endif
