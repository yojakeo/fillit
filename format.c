/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:18:13 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/03 04:07:31 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BCHECK(b) (pos + b >= 0 && pos + b <= 21)

/*
**	Converts the 4 lines from GNL into a single line to be confirmed and
**	converted to Directional Format and streamline the process.
*/

char	*gnltopiece(char ***gnlread)
{
	int		line;
	char	*piece;
	char	*tmp;

	line = 0;
	piece = ft_strnew(0);
	while (line != 5)
	{
		if (**gnlread)
		{
			if (!(tmp = ft_strjoin(piece, **(gnlread))))
				ERROR("GNL convert(alloc) fail!", NULL)
			ft_strdel(&piece);
			piece = tmp;
		}	
		if (!(tmp = ft_strjoin(piece, "\n")))
			ERROR("GNL convert(alloc) fail!", NULL)
		ft_strdel(&piece);
		piece = tmp;
		++(*gnlread);
		++line;
	}
	return (piece);
}

/*
**	confirms the formating of the piece by measuring 3 things:
**	The piece is made only of " # . \n ".
**	There are 4 '#' in the piece.
**	It is a 4 x 4 grid.
**	Each '#' is next to another '#' directly vertically or horizontally.
**	If it's valid then 0 is returned, else -1 is returned.
*/

int		format_confirm(char *piece)
{
	int blockcount;
	int	dotcount;
	int	pos;

	blockcount = 0;
	dotcount = 0;
	pos = -1;
	while (piece[++pos] && pos != 21)
	{
		if (!(piece[pos] == '.' || piece[pos] == '#' || piece[pos] == '\n'))
			ERROR("Piece format fail!(Invalid char)", -1)
		if (piece[pos] == '#')
			++blockcount;
		if (piece[pos] == '#' && !((BCHECK(-1) && piece[pos - 1] == '#') \
		|| piece[pos + 1] == '#' || (BCHECK(-5) && piece[pos - 5] == '#') \
		|| (BCHECK(5) && piece[pos + 5] == '#')))
			ERROR("Piece format fail!(No connected blocks)", -1)
		if (piece[pos] == '#' && piece[pos + 1] == '.' && piece[pos + 2] == '#')
			ERROR("Piece format fail!(Broken up piece)", -1)
		if (piece[pos] == '.')
			++dotcount;
	}
	if (piece[pos] || blockcount != 4 || pos != 21 || dotcount != 12)
		ERROR("Piece format fail!(Bad pos or block count)", -1)
	return (0);
}
