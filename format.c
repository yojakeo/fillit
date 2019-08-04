/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:18:13 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/04 03:42:01 by japarbs          ###   ########.fr       */
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
	if (**gnlread == NULL)
		return (NULL);
	while (line != 5)
	{
		if (**gnlread)
		{
			if (!(tmp = ft_strjoin(piece, **(gnlread))))
				return (NULL);
			ft_strdel(&piece);
			piece = tmp;
		}	
		if ((!**gnlread && line != 4) || !(tmp = ft_strjoin(piece, "\n")))
			return (NULL);
		ft_strdel(&piece);
		piece = tmp;
		++(*gnlread);
		++line;
	}
	return (piece);
}

/*
**	Checks the file for extra new lines after gnltopiece.
*/

int		gnl_check(char **gnlread)
{
	if ((*gnlread == NULL) || (*gnlread - 1 == NULL && *gnlread - 2 == NULL))
		return (0);
	return (1);
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
		if (piece[pos] == '#')
			++blockcount;
		if (piece[pos] == '.')
			++dotcount;
		if (piece[pos] == '#' && !((BCHECK(-1) && piece[pos - 1] == '#') \
		|| piece[pos + 1] == '#' || (BCHECK(-5) && piece[pos - 5] == '#') \
		|| (BCHECK(5) && piece[pos + 5] == '#')))
			return (-1);
		if (format_extra(piece, pos) == -1)
			return (-1);
	}
	if (piece[pos] || blockcount != 4 || pos != 21 || dotcount != 12)
		return (-1);
	return (0);
}

/*
**	Extra format checks. Checks for diagonals, broken up pieces.
*/

int		format_extra(char *piece, int pos)
{
	if (piece[pos] == '#' && piece[pos + 1] == '.' && piece[pos + 2] == '#')
		return (-1);
	if (piece[pos] == '#' && (piece[pos + 1] != '#' && piece[pos + 5] != '#') \
	&& (BCHECK(6) && piece[pos + 6] == '#'))
		return (-1);
	if (piece[pos] == '#' && piece[pos + 5] == '.' \
	&& (BCHECK(10) && piece[pos + 10] == '#'))
		return (-1);
	return (0);
}