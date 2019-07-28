/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:27:50 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/24 23:30:07 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
**	size of map = sqrt(number of pieces * 4)
**	functions to : 1. count pieces
**	2. get smallest possible map given number of pieces
**	3. place pieces recursively and backtrack if necessary
**	4. check if pieces overlap / in bounds of map
*/

/* 
**	Checks to see if current pos is '.'(empty) or if pointed to current piece
**	(tetindex + 'A') while backtracking on piece placement.
**	If theres no overlap, return 0(false), else return 1(true).
*/

int check_overlap(char mapchar, int tetindex)
{
	if(mapchar == '.' || mapchar == (tetindex + 'A'))
		return (0);
	return (1);
}

/* 
**	Checks to see if either axis is outside of bounds.
**	If outside it returns 0(false), else return 1(true).
*/

int check_inbounds(int x, int y, int size)
{
	if (x < 0 || y < 0 || x > size || y > size)
		return (0);
	return (1);
}

/*
**	shifts the anchor of the piece being built on the map.
**	checks for overlap & bounds.
*/

void	progress_anchor(int *y, int *x, char **map, char *tetrimap)
{

}

void	progress_placement(int *y, int *x, char tetriblock)
{
	if (tetriblock == 'R')
		++x[0];
	else if (tetriblock == 'L')
		--x[0];
	else if (tetriblock == 'D')
		++y[0];
}

int	insert_pieces(char **tetrimap, char ***map)
{
	progress_placement()
	return (0);
}

