/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:20:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/22 21:51:18 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define LCHECK	(tetrimap[i[0] - 1] == '#')
#define DCHECK	(tetrimap[i[0] + 5] == '#')
#define RCHECK	(tetrimap[i[0] + 1] == '#')

/*
**	Converts 21 char strings to "Directional Format"
**	key Legend: S is start(anchor), R is right, D is down, U is up, L is left.
**	S is always the upper most left pound of the piece (height being priority).
**	piece_convert takes the tetromino and converts it to a map of the piece
**	using the above legend, S always is at the start.
**	      The following piece would be formated in *tetrimap[27] as "SDRLL".
**	..#.  After each char read it would place that block of the piece.
**	.###  Essentially guiding the program though the piece from the anchor.
*/

char	*piece_convert(char *tetrimap)
{
	char	*res;
	char	*tmp;
	int		pos;
	int		blockcount;
	char	*c;

	pos = 0;
	blockcount = 0;
	while (tetrimap[pos] != '#')
		++pos;
	res = ft_strdup("S");
	while (tetrimap[pos])
	{
		if ((c = block_test(tetrimap, &pos, res, &blockcount)) == NULL)
			ERROR("Convert fail!", NULL)
		else if (c[0] == 'E')
			break;
		tmp = ft_strjoin(res, c);
		ft_strdel(&res);
		res = tmp;
	}
	return (res);
}

/*
**	Tests to see if block has been mapped yet. if so it returns the proper
**	char for the direction. If not it returns NULL.
**	CASES
**	Cast priority:
**	if R = true return "R".
**	if D = true && R = false return "D".
**	if L = true && D and R = false return "L".
**	program should never need to go up. Since it starts from the top-left down.
**	if only 1 connected block from iterated point and 
**	the blockcount is not 4, go back. (EX: If last cycle
**	added R (right), add an L (left) to go back to last point.)
**	
*/

char	*block_test(char *tetrimap, int *i, char *res, int *blockcount)
{
	int	resi;

	resi = 0;
	while (res[resi + 1])
		++resi;
	// if (blockcount[0] == 3)
	// {
	// 	blockcount[0] = 0;
	// 	return ("E");
	// }
	if (!DCHECK && ((!RCHECK && !LCHECK) || \
	((LCHECK || RCHECK) && (res[resi] == 'R' || res[resi] == 'L'))))
		return ("E");
	else if (DCHECK && ((!RCHECK && !LCHECK) || \
	((LCHECK || RCHECK) && (res[resi] == 'R' || res[resi] == 'L'))))
	{
		i[0] += 5;
		++blockcount[0];
		return ("D");
	}
	else if (LCHECK && !RCHECK && res[resi] != 'L')
	{
		--i[0];
		++blockcount[0];
		return ("L");
	}
	else if (RCHECK)
	{
		++i[0];
		++blockcount[0];
		return ("R");
	}
	// else if (!DCHECK && ((!RCHECK && !LCHECK) || \
	// ((LCHECK || RCHECK) && (res[resi] == 'R' || res[resi] == 'L'))))
	// 	return ("E");
	return ("E");
}
