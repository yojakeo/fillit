/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:27:50 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/24 23:30:07 by jetownle         ###   ########.fr       */
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
** checks to see if the coordinates given to the function have a '.'
** or letter/# at the x/y coordinates
*/

int check_overlap(char **map, int x, int y)
{
	placement = map[x][y];
	if(placement == '.')
	{
		return (1);
	}
	else
	{
		return (0);
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
		return (1);
	else
		return (0);
}

/* shifts the anchor of the piece being built on the map */
void	shift_anchor_x(//anchors current location//, int n)
{
	//anchors current location// += n;
}

void	shift_anchor_y(//anchors current location//, int n)
{
	//anchors current location// += n;
}

char **insert_pieces(char **tetrimap, char ***map)
{

}

