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
#define BRETURN(n, c) {i[0] += n; ++blockcount[0]; return (c);}

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
	int		i;
	int		blockcount;
	char	*c;

	i = 0;
	blockcount = 0;
	while (tetrimap[i] != '#')
		++i;
	res = ft_strdup("S");
	while (blockcount != 4)
	{
		if ((c = block_test(tetrimap, res, &i, &blockcount)) == NULL)
			ERROR("Convert fail!", NULL)
		else if (c[0] == 'E')
			break;
		if (!(tmp = ft_strjoin(res, c)))
			ERROR("Convert(alloc) fail!", NULL)
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
*/

char	*block_test(char *tetrimap, char *res, int *i, int *blockcount)
{
	int		resi;
	char	*c;

	resi = 0;
	while (res[resi + 1])
		++resi;
	if ((c = check_backtrack(tetrimap, res, i, blockcount)) != NULL)
		return (c);
	else if (LCHECK && !RCHECK && res[resi] != 'L')
		BRETURN(-1, "L")
	else if (DCHECK && ((!RCHECK && !LCHECK) || \
	((LCHECK || RCHECK) && (res[resi] == 'R' || res[resi] == 'L'))))
		BRETURN(5, "D")
	else if (RCHECK)
		BRETURN(1, "R")
	else if (!DCHECK && ((!RCHECK && !LCHECK) || \
	((LCHECK || RCHECK) && (res[resi] == 'R' || res[resi] == 'L'))))
		return ("E");
	return (NULL);
}

/*
**	Checks for if in need to back track. The following pieces require it.
**	###. ##.. .#.. #... ###. .#.. .##.
**	#... #... ###. ##.. .#.. ##.. ##..
**		 #...	   #...      .#..
*/

char	*check_backtrack(char *tetrimap, char *res, int *i, int *blockcount)
{
	int resi;

	resi = 0;
	while (res[resi + 1])
		++resi;
	if (blockcount[0] == 3 && !RCHECK && !DCHECK && LCHECK && \
	tetrimap[i[0] - 2] == '#' && tetrimap[i[0] + 3] == '#')
		BRETURN(3, "LLD");
	return (NULL);
}




