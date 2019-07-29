/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:27:02 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/29 06:38:32 by jetownle         ###   ########.fr       */
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
**	Macros
*/
# define	ERROR(msg, r) {ft_putendl(msg); return(r);} 
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
	int					anchor[26][2];
	int 				i;
	int 				count;
}						t_piece;
/*
**	Cores
*/
int						format_core(char **gnlread, t_piece *pieces);
int						solve_core(char **tetrimap, char ***map, int count);
int						backtrack_core(char **tetrimap, char ***map);
void					finish_core(char **map, char **tetrimap, char **gnlread, int count);
/*
**	Format
*/
char					*gnltopiece(char ***gnlread);
int						format_confirm(char *piece);
/*
**	Converting
*/
char					*piece_convert(char *tetrimap);
char					*block_test(char *tetrimap, char *res, int *i, int *blockcount);
char					*check_backtrack(char *tetrimap, char *res, int *i, int *blockcount);
/*
**	Solving
*/
int						check_overlap(char mapchar, int tetindex);
int						check_inbounds(int x, int y, int size);
void					follow_piece(t_map map, t_piece piece, char c);
int						insert_pieces(char **tetrimap, char ***map);
void					progress_placement(int *y, int *x, char tetriblock);
void					progress_anchor(int *y, int *x, char **map, char *tetrimap);
int						check_placement(char **tetrimap, char ***map, int *x, int *y);
int						remove_piece(char **tetrimap, int tetindex, char ***map, int *x, int *y);
int						recurse(t_piece pieces, t_map map, t_pos pos);
/*
**	Reading
*/
char					**ft_readfd(int fd, size_t size);
/*
**	Map Functions
*/
int						map_start(int count);
char					**make_map(int size);
void					printmap(char **map, int size);
void					freemap(char **map, int size);
/*
**	Fillit Main
*/
int						fillit(int fd);
#endif
