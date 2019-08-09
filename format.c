/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:18:13 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/08 15:51:14 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BCHECK(b) (pos + b >= 0 && pos + b <= 21)

/*
**	Converts the 4 lines from GNL into a single line to be confirmed and
**	converted to Directional Format and streamline the process.
**	if there's a NULL string before the 5th string it returns NULL.
*/

char	*gnltopiece(char ***gnlread)
{
	int		line;
	char	*piece;
	char	*tmp;

	line = 0;
	piece = ft_strnew(0);
	if (!**gnlread)
		return (NULL);
	while (line != 5)
	{
		if (**gnlread)
		{
			if (!(tmp = ft_strjoin(piece, **gnlread)))
				return (NULL);
			ft_strdel(&piece);
			piece = tmp;
		}
		if ((!**gnlread && line != 4) || !(tmp = ft_strjoin(piece, "\n")))
			return (NULL);
		ft_strdel(&piece);
		piece = tmp;
		++*gnlread;
		++line;
	}
	return (piece);
}

/*
**	Confirms the formating of the piece by measuring mainly these 5 things:
**	The piece is made only of " # . \n ".
**	There are 4 '#' in the piece along with 12 '.' chars.
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
			return (-1);
		if (piece[pos] == '.')
			++dotcount;
		if (piece[pos] == '#')
			format_connect(piece, pos, &blockcount);
	}
	if (piece[pos] || !(blockcount >= 6 && blockcount <= 8) \
	|| pos != 21 || dotcount != 12)
		return (-1);
	return (0);
}

/*
**	Checks for connections. For each connection blockcount is iterated.
*/

void	format_connect(char *piece, int pos, int *blockcount)
{
	if (piece[pos + 1] == '#')
		++*blockcount;
	if (BCHECK(-1) && piece[pos - 1] == '#')
		++*blockcount;
	if (BCHECK(-5) && piece[pos - 5] == '#')
		++*blockcount;
	if (BCHECK(5) && piece[pos + 5] == '#')
		++*blockcount;
}
