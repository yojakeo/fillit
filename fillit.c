/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/03 05:00:16 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The home of all calls in Fillit, launches Core functions.
*/

int		fillit(int fd)
{
	char	**gnlread;
	t_map	map;
	t_piece	pieces;

	gnlread = ft_readfd(fd);
	(void)map;
	if (format_core(gnlread, &pieces) == -1)
		return (-1);
	if (solve_core(&pieces, &map) == -1)
		return (-1);
	finish_core(&map, &pieces, gnlread);
	return (0);
}

/*
**		Sudo code / function planning
**	Fillit finds the smallest possible square for up to 26 tetromino to fit
**	into via an algorithm.
**
**		Planned modules
**	Function to take GNL's **line and converts & confirms pieces.
**	Uses chars to guide the program (sudlr, to guide the program
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
*/
