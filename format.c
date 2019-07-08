/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:18:13 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/08 16:42:24 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	confirms the formating of the piece by mesuring 3 things. The piece is
**	a 4x4 grid, each part is connected to another via x and y, and there
**	are 4 '#' chars in the piece. Else -1 is returned.
*/

char	*gnltopiece(char **gnlread)
{
	int		line;
	char	*piece;
	char	*tmp;

	while (line != 4)
	{
		if (!(tmp = ft_strjoin(piece, *(gnlread))))
			return (NULL);
		ft_strdel(&piece);
		piece = tmp;
		++gnlread;
		++line;
	}
	return (piece);
}

int		format_confirm(char *piece)
{
	int blockcount;
	int	pos;

	while (pos < 20)
	{
		if ()
	}
}
