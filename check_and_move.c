/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:27:50 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/29 08:07:19 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
**	size of map = sqrt(number of pieces * 4)
**	functions to : 1. count pieces
**	2. get smallest possible map given number of pieces
**	3. place pieces recursively and backtrack if necessary
**	4. check if pieces overlap / in bounds of map
*/

/* 
**	Checks to see if current pos is '.'(empty).
**	If theres no overlap, return 0(false), else return 1(true).
*/

int check_overlap(char mapchar)
{
	if (mapchar == '.')
		return (1);
	return (0);
}

/* 
**	Checks to see if either axis is outside of bounds.
**	If outside it returns 0(false), else return 1(true).
*/

int check_inbounds(int y, int x, int size)
{
	if (x < 0 || y < 0 || x > size || y > size)
		return (1);
	return (0);
}

/*
**	Takes the piece and tests to see if the piece is in a valid spot. Flowing
**	through the piece via Directional Format. If inbounds and there's no overlap
**	it goes though and writes the piece down in the map with it's correct char
**	with the place_piece function.
*/

int	check_piece(t_map *map, t_piece *pieces, t_pos pos)
{
	int	i;
	int y;
	int x;

	i = -1;
	y = pos.y;
	x = pos.x;
	while (pieces->pieces[pieces->i][++i]) 
	{
		progress_placement(&y, &x, pieces->pieces[pieces->i][i]);
		if (!(check_inbounds(y, x, map->size) && check_overlap(map->map[y][x])))
			return (0);
	}
	place_piece(map, pieces, pos, (pieces->i + 'A'));
	return (1);
}

/*
**	Moves the indexes toward where the placement should go via
**	Directional Formating.
*/

void	progress_placement(int *y, int *x, char tetriblock)
{
	if (tetriblock == 'R')
		++x[0];
	else if (tetriblock == 'L')
		--x[0];
	else if (tetriblock == 'D')
		++y[0];
}
