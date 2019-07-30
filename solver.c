/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:41:18 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/29 08:18:25 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** 1. take directionally formatted piece and place it in top left corner
** 2. take second piece and use directional format of piece to check all 
** places of piece relative to anchor for overlap / out of bounds
** 3. place piece in checked position
** 4. take third piece and check position, if all possible positions have
** been checked and still no solution, remove previous piece and try
** another position
** 5. if all else fails, increase map size
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
** try to solve the map, if it fails increase map size and call it again
*/

int		solve_map(t_piece *pieces, t_map *map)
{
	t_pos		*pos;


	if (!pieces->pieces[pieces->i])
		return (1);
	pos->y = -1;
	while (++pos->y < map->size)
	{
		pos->x = -1;
		while (++pos->x < map->size)
		{
			if (check_piece(map, pieces, *pos))
			{
				if (solve_map(pieces, map))
					return (1);
				else
					place_piece(map, pieces, *pos, '.');
			}
		}
	}
	return (0);
}

// int solve_map(t_piece *pieces, t_map *map, t_pos *pos)
// {
// 	if ()
// 	{	
// 		while (check_inbounds(pos->x, pos->y, map->size))
// 		{
// 			if (check_overlap((map->map[pos->y][pos->x])))
// 				place_piece(map, pieces, pieces->i);
// 			if (solve_map(pieces, map, pos)
// 					return (1);
// 			else
// 				remove_piece(map, pieces);
// 		}
// 	}
// 	else
// 	{
// 		freemap(map, map.size);
// 		map.size++;
// 		make_map(map.size);
// 		solve_map(pieces, map, pos);
// 	}
// 	return (0);
// }
