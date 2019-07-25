/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:32:19 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/25 00:01:39 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
**	Creates the map of the working area of the size given. ex: if size = 5
**	function creates a 6x6 double pointer for NULL termination. Then bzeros
**	the fresh double pointer.
*/

char	**make_map(int size)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ft_bzero(map, (size + 1));
	while (map[++i + 1])
	{
		if (!(map[i] = ft_strnew(size)))
			return (NULL);
		ft_memset(map[i], '.', size);
	}
	return (map);
}

void	printmap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

void	freemap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
}

