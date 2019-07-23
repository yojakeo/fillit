/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:27:50 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/23 13:53:02 by jetownle         ###   ########.fr       */
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
**	Function to calculate smallest possible square and allocate memory accordingly
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

