/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:27:50 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/23 19:25:59 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
**	size of map = sqrt(number of pieces * 4)
**	functions to : 1. count pieces
**	2. get smallest possible map given number of pieces
**	3. place pieces recursively and backtrack if neccesary
**	4. check if pieces overlap / in bounds of map
*/

/*
**	Function to calculate smallest possible square
*/

int	map_start(int count)
{
	int size;
	int	blocks;

	size = 2;
	blocks = count * 4;
	while(size * size < blocks)
		size++;
	return (size);
}

/* 
** checks to see if the coordinates given to the function have a '.'
** or letter/# at the x/y coordinates
*/
int check_overlap(char **map, int x, int y)
{
	placement = map[x][y];
	if(placement == '.')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

/* 
** finds the boundaries of the given map 
** and checks if the x/y coords are within them
*/
int check_inbounds(char **map, int x, int y)
{
	int boundx;
	int boundy;
	
	while(map[boundx][boundy] != '\0')
	{
		boundx++;
		boundy++;
	}

	if(x <= boundx && y <= boundy)
		return 1;
	else
		return 2;
}

char **insert_pieces(char **tetrimap, char ***map)
{

}

