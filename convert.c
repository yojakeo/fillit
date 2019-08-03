/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:20:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/03 04:08:51 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BCHECK(b) (*i + b >= 0 && *i + b <= 21)
#define LCHECK	(*i - 1 >= 0 && piece[*i - 1] == '#')
#define DCHECK	(*i + 5 <= 21 && piece[*i + 5] == '#')
#define RCHECK	(*i + 1 <= 21 && piece[*i + 1] == '#')

/*
**	Converts 21 char strings to "Directional Format"
**	key Legend: S is start(anchor), R is right, D is down, L is left.
**	S is always the upper most left pound of the piece (height being priority).
**	piece_convert takes the tetromino and converts it to a map of the piece
**	using the above legend, S always is at the start.
**	      The following piece would be formated in *piece[27] as "SDRLL".
**	..#.  After each char read it would place that block of the piece.
**	.###  Essentially guiding the program though the piece from the anchor.
*/

char	*piece_convert(char *piece)
{
	char	*res;
	char	*tmp;
	int		i;
	int		blockcount;
	char	*c;

	i = 0;
	blockcount = 0;
	while (piece[i] != '#')
		++i;
	res = ft_strdup("S");
	while (blockcount != 4)
	{
		if ((c = block_test(piece, res, &i, &blockcount)) == NULL)
			ERROR("Convert fail!", NULL);
		if (c[0] == 'E')
			break ;
		if (!(tmp = ft_strjoin(res, c)))
			ERROR("Convert(alloc) fail!", NULL);
		ft_strdel(&res);
		res = tmp;
	}
	ft_strdel(&piece);
	return (res);
}

/*
**	Function to aid for returns in block_test and check_backtrack.
*/

char	*breturn(int *i, int amt, int *blockcount, char *charres)
{
	*i += amt;
	++blockcount[0];
	return (charres);
}

/*
**	Tests to see if block has been mapped yet. if so it returns the proper
**	char for the direction. If not it returns NULL.
**	CASES
**	D is Down, L is Left, R is Right.
**	Return priority:
**	If D && NOT R & L are return "D".
**	If L = true && D and R = false return "L".
**	If R && previously didn't go L, return "R".
**	program should never need to go up. Since it starts from the top-left down.
**	if only 1 connected block from iterated point and
**	the blockcount is not 4, go back. (EX: If last cycle
**	added R (right), add an L (left) to go back to last point.)
*/

char	*block_test(char *piece, char *res, int *i, int *blockcount)
{
	int		resi;
	char	*c;

	resi = 0;
	while (res[resi + 1])
		++resi;
	if ((c = check_backtrack(piece, res, i, blockcount)) != NULL)
		return (c);
	else if (DCHECK && ((!RCHECK && !LCHECK) || \
	((LCHECK || RCHECK) && (res[resi] == 'R' || res[resi] == 'L'))))
		return (breturn(i, 5, blockcount, "D"));
	else if (LCHECK && !RCHECK && res[resi] != 'R')
		return (breturn(i, -1, blockcount, "L"));
	else if (RCHECK && res[resi] != 'L')
		return (breturn(i, 1, blockcount, "R"));
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

char	*check_backtrack(char *piece, char *res, int *i, int *blockcount)
{
	int resi;

	resi = 0;
	while (res[resi + 1])
		++resi;
	if (BCHECK(3) && BCHECK(-2) && !RCHECK && !DCHECK && LCHECK && \
	piece[*i - 2] == '#' && piece[*i + 3] == '#')
		return (breturn(i, 3, blockcount, "LLD"));
	else if (BCHECK(4) && !RCHECK && LCHECK && !DCHECK && piece[*i + 4] == '#' \
	&& res[resi] == 'R')
		return (breturn(i, 4, blockcount, "LD"));
	else if (BCHECK(6) && RCHECK && !LCHECK && !DCHECK && piece[*i + 6] == '#' \
	&& res[resi] == 'L')
		return (breturn(i, 6, blockcount, "RD"));
	else if (BCHECK(-6) && !RCHECK && LCHECK && piece[*i - 2] == '#' && piece[*i - 6] == '#' \
	&& res[resi] == 'R')
		return (breturn(i, -2, blockcount, "LL"));
	else if (RCHECK && LCHECK && DCHECK && res[resi] == 'R')
		return (breturn(i, 5, blockcount, "RLD"));
	return (NULL);
}
