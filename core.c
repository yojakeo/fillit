/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:04:20 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/06 00:12:16 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Core of Format related functions. Take's GNL's output and converts to
**	21 char pieces that are pushed to *pieces[27], checks format, then converts
**	to Directional Format. If any function fails, -1 is returned.
*/

int		format_core(char **gnlread, t_piece *pieces)
{
	pieces->count = 0;
	if (!gnlread)
		return (-1);
	while (*gnlread)
	{
		if (pieces->count == 27)
			return (-1);
		if ((!(pieces->pieces[pieces->count] = gnltopiece(&gnlread))) \
		|| (format_confirm(pieces->pieces[pieces->count])) \
		|| (!(pieces->pieces[pieces->count] = \
		piece_convert(pieces->pieces[pieces->count]))))
			return (-1);
		++pieces->count;
	}
	pieces->pieces[pieces->count] = NULL;
	return (0);
}

/*
**	Core of Solving related functions. Calculates the starting map size and
**	makes it before passing it to Solve_map. If solve map fails it makes a
**	new map one size bigger.
*/

int		solve_core(t_piece *pieces, t_map *map)
{
	int i;

	i = 0;
	pieces->i = 0;
	map->size = map_start(pieces->count);
	if (!(map->map = make_map(map->size)))
		return (-1);
	while (!solve_map(pieces, map))
	{
		++map->size;
		freemap(map);
		if (!(map->map = make_map(map->size)))
			return (-1);
	}
	return (0);
}

/*
**	Finishes up Fillit by printing the map and freeing all memory.
*/

void	finish_core(t_map *map, t_piece *pieces, char **gnlread)
{
	int i;

	printmap(*map);
	freemap(map);
	i = -1;
	while (pieces->count > ++i)
		ft_strdel(&pieces->pieces[i]);
	i = 0;
	while (gnlread[i])
		ft_strdel(&gnlread[i++]);
	free(gnlread);
	gnlread = NULL;
}
