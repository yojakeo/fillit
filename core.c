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
**	Core of Format related functions for GNL -> 21 char piece strings to be
**	validated. Then converted from 21 char strings to Directional Format.
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
	tetindex = 0;
	while (tetrimap[tetindex])
		printf("%s\n", tetrimap[tetindex++]);
	return (0);
}

int solve_core(char **tetrimap, char ***map, int count)
{
	if (check_inbounds(char **map, int x, int y))
	{
		if (check_overlap(char **map, int x, int y))
		{
			insert_pieces(char **tetrimap, char ***map);

	if (!(count))
		ERROR("Solve core fail!", -1)
	return (0);
}
