/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:32:19 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/01 21:50:03 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Function to calculate smallest possible square that fits all pieces.
*/

int		map_start(int count)
{
	int size;
	int	blocks;

	size = 2;
	blocks = count * 4;
	while (size * size < blocks)
		size++;
	return (size);
}

/*
**	Creates the map of the working area of the size given. ex: if size = 5
**	function creates a 6x6 double pointer for NULL termination. Then bzeros
**	the fresh pointers before setting each point to '.'(empty).
*/

char	**make_map(int size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		ERROR("Make_map alloc fail!(Double Pointer)", NULL);
	ft_bzero(map, (size + 1));
	while (++i <= size)
	{
		if (!(map[i] = ft_strnew(size)))
			ERROR("Make_map alloc fail!(Single Pointer)", NULL);
		ft_memset(map[i], '.', size);
	}
	map[size + 1] = NULL;
	return (map);
}

/*
**	Prints the map.
*/

void	printmap(t_map map)
{
	int i;

	i = 0;
	while (i <= map.size)
		ft_putendl(map.map[i++]);
}

/*
**	Frees the map and its child pointers.
*/

void	freemap(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
		ft_strdel(&map->map[i++]);
	ft_strdel(map->map);
}
