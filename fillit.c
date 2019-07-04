/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/04 09:08:23 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

# define MINMAPSIZE(tcount) tcount * 4

int		fillit(int fd)
{
	char **gnlread;
	char **map;
	static char *tetrimap[27];

	gnlread = ft_readfd(fd);


}

char **ft_readfd(int fd)
{
	char **gnlread;

	while (get_net_line(fd, gnlread))
		++(line);
	return (gnlread);
}
/*
**	key Legend: S is start(anchor), R is right, D is down, U is up, L is left.
**	S is always the upper most left pound of the piece.
**	piece_convert takes the tetrinmo and converts it to a map of the piece
**	using the above legend, S always is at the start
**	..#.  following piece would be formated in *tetrimap[27] as
**	.###  "SDLRR", after each char read it would place that part of the piece.
*/
char	*piece_convert(char **gnlread, static char *tetrimap)
{

}
/*
**	confirms the formating of the piece by mesuring 3 things. The piece is
**	a 4x4 grid, each part is connected to another via x and y, and there
**	are 4 '#' chars in the piece. Else -1 is returned.
*/
int		format_confirm(char **gnlread)
{
	int partcount;
	int	x;
	int	y;

	while ()
}

/*
**		Sudo code / function planning
**	Fillit finds the smallest possible square for up to 26 tetrimenos to fit
**	into via an algorithm.
**
**		Planned modules
**	Function to take GNL's **line and converts & confirms pieces.
**	Uses chars to guide the program (shjkl, to guide the program
**	though the piece.)
**
**	Algorithm to make a piece fit within current square.
**
**	To save cycles. Before algorithm starts it'll calculate the smallest
**	possible square within (pieces x 4) rather than starting from 2x2.
**
**	module to display square and the lettered pieces in the square.
**
**	Linked list OR map to keep track of pieces.
**	
*/