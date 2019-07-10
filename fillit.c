/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/09 21:08:24 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

# define MINMAPSIZE(tcount) tcount * 4

int		fillit(int fd)
{
	char **gnlread;
	char **map;
	static char *tetrimap[27];
	size_t	index;

	(void)map;
	index = 0;
	gnlread = ft_readfd(fd, 132);
	while (gnlread)
	{
		if ((tetrimap[index] = gnltopiece(gnlread)) == NULL)
			return (-1);
		if ((format_confirm(tetrimap[index])) \
		/*|| (piece_convert(tetrimap[index]))*/ == -1)
		 	return (-1);
		++index;
	}
	index = 0;
	while (tetrimap[index])
		printf("%s\n", tetrimap[index++]);
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
**	
*/
