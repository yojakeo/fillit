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
		if (pieces->count == 27)
			ERROR("Format core fail!(Too many pieces, max 26)", -1)
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

int solve_core(t_piece *pieces, t_map *map)
{
	int i;

	i = 0;
	map->size = map_start(pieces->count);
	while (!solve_map(pieces, map))
	{
		++map->size;
		freemap(map);
		map->map = make_map(map->size);
	}
	return (0);
}

void	finish_core(t_map *map, t_piece *pieces, char **gnlread)
{
	int i;

	printmap(*map);
	freemap(map);
	i = 0;
	while (pieces->count > i++)
		ft_strdel(&pieces->pieces[i++]);
	ft_strdel(pieces->pieces);
	i = 0;
	while (gnlread[i])
		ft_strdel(&gnlread[i++]);
	ft_strdel(gnlread);
}
