/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:41:18 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/01 21:03:16 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Places the piece with the guidance of Directional Formatting. Each step
**	setting that index to the given char.
*/

void	place_piece(t_map *map, t_piece *pieces, t_pos pos, char c)
{
	int	i;
	int y;
	int x;

	i = -1;
	y = pos.y;
	x = pos.x;
	while (pieces->pieces[pieces->i][++i])
	{
		progress_placement(&y, &x, pieces->pieces[pieces->i][i]);
		map->map[y][x] = c;
	}
}

/*
**	Solves the map. Iterates though the map top down, left to right
**	attempting to place piece. If it does it selects the next piece and
**	recurses. If the recursion fails it deletes the piece and tries again
**	on the next iteration. If all fails, it returns 0 for
**	Solve_core to increase the map size.
*/

int		solve_map(t_piece *pieces, t_map *map)
{
	t_pos		pos;

	if (!pieces->pieces[pieces->i])
		return (1);
	pos.y = -1;
	while (++pos.y < map->size)
	{
		pos.x = -1;
		while (++pos.x < map->size)
		{
			if (check_piece(map, pieces, pos))
			{
				++pieces->i;
				if (solve_map(pieces, map))
					return (1);
				else
				{
					--pieces->i;
					place_piece(map, pieces, pos, '.');
				}
			}
		}
	}
	return (0);
}
