/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:27:02 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/04 04:47:47 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libftplus/libft.h"

/*
**	Structs
*/
typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_map
{
	int					size;
	char				**map;
}						t_map;

typedef struct			s_piece
{
	char				*pieces[27];
	int					i;
	int					count;
}						t_piece;
/*
**	Cores
*/
int						format_core(char **gnlread, t_piece *pieces);
int						solve_core(t_piece *pieces, t_map *map);
void					finish_core(t_map *map, t_piece *pieces,
						char **gnlread);
/*
**	Reading
*/
char					**ft_readfd(int fd);
/*
**	Format
*/
char					*gnltopiece(char ***gnlread);
int						format_confirm(char *piece);
int						format_extra(char *piece, int pos);
/*
**	Converting
*/
char					*piece_convert(char *tetrimap);
char					*block_test(char *tetrimap, char *res, int *i,
						int *blockcount);
char					*check_backtrack(char *tetrimap, char *res, int *i,
						int *blockcount);
/*
**	Solving & Checks
*/
int						check_overlap(char mapchar);
int						check_inbounds(int x, int y, int size);
int						solve_map(t_piece *pieces, t_map *map);
/*
**	Placement
*/
void					place_piece(t_map *map, t_piece *pieces, t_pos pos,
						char c);
int						check_piece(t_map *map, t_piece *pieces, t_pos pos);
void					progress_placement(int *y, int *x, char tetriblock);
/*
**	Map Functions
*/
int						map_start(int count);
char					**make_map(int size);
void					printmap(t_map map);
void					freemap(t_map *map);
/*
**	Fillit Main
*/
int						fillit(int fd);
/*
**	Return Handling
*/
char					*breturn(int *i, int amt, int *blockcount,
						char *charres);
#endif
