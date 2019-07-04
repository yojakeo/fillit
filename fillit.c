/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/02 21:12:53 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
**	key Legend: S is start, H is right, J is down, K is up, L is left.
**	S is always the upper most left pound of the piece.
**	piece_convert takes the tetrinmo and converts it to a map of the piece
**	using the above legend, S always is at the start
*/
char	*piece_convert(char **gnlread, static char *tetrimap[27])
{

}

int		format_confirm()
{

}

/*
**		Sudo code / function planning
**	Fillit finds the smallest possible square for up to 26 tetrimenos to fit
**	into via an algorithm.
**
**		Planned modules
**	Function to take GNL's **line and converts & confirms pieces.
**	Perhaps could use chars to guide the program (hjkl, to tell the program to
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