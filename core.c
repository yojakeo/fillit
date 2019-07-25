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
	size_t	tetindex;

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
	while (tetrimap[tetindex])
		printf("%s\n", tetrimap[tetindex++]);
	return (0);
}

/*
**	Core of Solving related fucntions.
*/

int solve_core(char **tetrimap, char ***map, int count)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (check_inbounds(*(map), x, y))
	{
		if (check_overlap(*(map), x, y))
		{
			insert_pieces(tetrimap, map);
		}
	if (!(count))
		ERROR("Solve core fail!", -1)
	return (0);
}
