/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/13 21:08:18 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The home of all calls in Fillit, launches Core functions.
*/

int		fillit(int fd)
{
	char	**gnlread;
	char	**map;
	char	*tetrimap[27];

	gnlread = ft_readfd(fd, 132);
	(void)map;
	if (format_core(gnlread, tetrimap) == -1)
		return (-1);
	return (0);
}

/*
**	Creates the map of the working area of the size given. ex: if size = 5
**	function creates a 6x6 double pointer for NULL termination. Then bzeros
**	the fresh double pointer.
*/

char	**make_map(int size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ft_bzero(map, (size + 1));
	while (map[++i + 1])
		if (!(map[i] = ft_strnew(size)))
			return (NULL);
	return (map);
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
