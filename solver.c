/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 05:41:18 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/28 06:45:13 by jetownle         ###   ########.fr       */
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

/*
** guided by direction format, checks all locations of piece for
** overlap / out of bounds
*/

int check_placement(char **tetrimap, char ***map, int *x, int *y)
{

}

int remove_piece(char **tetrimap, int tetindex, char ***map. int *x, int *y)
{
	
}

/* 
** try to solve the map, if it fails increase map size and call it again
*/

int recurse(char **tetrimap, int tetindex, char ***map, int x, int y)
{
	if ()
	{
		while (check_inbounds(x, y, size))
		{
			if (check_overlap((*map[y][x]), tetindex))
				insert_pieces(tetrimap, map);
			else
				remove_piece(tetrimap, tetindex, map, x, y);
		}
	}
	else
	{
		freemap(map, size);
		size++;
		make_map(size);
		recurse();
	}
}
