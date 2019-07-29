/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:04:20 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/28 06:45:40 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Core of Format related functions. Pushes raw 21 char pieces from GNL to
**	*tetrimap[27], checks format, then converts to Directional Format.
**	If any function fails, -1 is returned.
*/

int	format_core(char **gnlread, t_piece *pieces)
{
	int i;

	i = 0;
	while (*(gnlread))
	{
		if ((!(pieces->pieces[i] = gnltopiece(&gnlread))) \
		|| (format_confirm(pieces->pieces[i])) \
		|| (!(pieces->pieces[i] = piece_convert(pieces->pieces[i]))))
			ERROR("Format core fail!", -1)
		++i;
		++pieces->count;
	}
	pieces->pieces[i] = NULL;
	i = 0;
	while (i < pieces->count)
		printf("%s\n", pieces->pieces[i++]);
	printf("%i\n", pieces->count);
	return (0);
}

/*
**	Core of Solving related functions.
*/

int solve_core(char **tetrimap, char ***map, int count)
{
	t_pos		x;
	t_pos		y;
	int			tetindex;
	int			size;

	tetindex = 0;
	size = map_start(count);
	map = make_map(size);
	recurse(tetrimap, tetindex, map, x, y);
	return (0);
}

int	backtrack_core(char **tetrimap, char ***map)
{
	return (0);
}

void	finish_core(t_map map, t_piece pieces, char **gnlread)
{
	int i;

	// i = 0;
	// while(map[i])
	// 	ft_strdel(&map[i++]);
	// ft_strdel(map);
	i = 0;
	while (pieces.count > i++)
		ft_strdel(&pieces.pieces[i++]);
	ft_strdel(pieces.pieces);
	i = 0;
	while (gnlread[i])
		ft_strdel(&gnlread[i++]);
	ft_strdel(gnlread);
}
