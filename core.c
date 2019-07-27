/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:04:20 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/23 19:44:49 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Core of Format related functions. Pushes raw 21 char pieces from GNL to
**	*tetrimap[27], checks format, then converts to Directional Format.
**	If any function fails, -1 is returned.
*/

int	format_core(char **gnlread, char **tetrimap, int *count)
{
	int	tetindex;

	tetindex = 0;
	while (*(gnlread))
	{
		if ((!(tetrimap[tetindex] = gnltopiece(&gnlread))) \
		|| (format_confirm(tetrimap[tetindex])) \
		|| (!(tetrimap[tetindex] = piece_convert(tetrimap[tetindex]))))
			ERROR("Format core fail!", -1)
		++tetindex;
		++count[0];
	}
	tetrimap[tetindex] = NULL;
	tetindex = 0;
	while (tetindex < count[0])
		printf("%s\n", tetrimap[tetindex++]);
	return (0);
}

/*
**	Core of Solving related fucntions.
*/

int solve_core(char **tetrimap, char ***map, int count)
{
	static int	x;
	static int	y;
	int			tetindex;
	int			size;

	tetindex = 0;
	size = map_start(count);
	while (check_inbounds(x, y, size))
	{
		if (check_overlap(*(map), tetindex, x, y))
			insert_pieces(tetrimap, map);
	}
	return (0);
}

int	backtrack_core(char **tetrimap, char ***map)
{
	return (0);
}

void	finish_core(char **map, char **tetrimap, char **gnlread, int count)
{
	int i;

	// i = 0;
	// while(map[i])
	// 	ft_strdel(&map[i++]);
	// ft_strdel(map);
	i = 0;
	while (count > i++)
		ft_strdel(&tetrimap[i++]);
	ft_strdel(tetrimap);
	i = 0;
	while (gnlread[i])
		ft_strdel(&gnlread[i++]);
	ft_strdel(gnlread);
}
