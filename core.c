/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:04:20 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/23 13:53:06 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Core of Format related functions for GNL -> 21 char piece strings to be
**	validated. Then converted from 21 char strings to Directional Format.
*/

int	format_core(char **gnlread, char **tetrimap)
{
	size_t	tetindex;
	size_t	gnlindex;

	tetindex = 0;
	gnlindex = 0;
	while (gnlread[gnlindex])
	{
		if ((!(tetrimap[tetindex] = gnltopiece(&gnlread[gnlindex]))) \
		|| (format_confirm(tetrimap[tetindex])) \
		/*|| (!(tetrimap[tetindex] = piece_convert(tetrimap[tetindex]))*/)
			return (-1);
		++tetindex;
		gnlindex += 5;
	}
	tetindex = 0;
	while (tetrimap[tetindex])
		printf("%s", tetrimap[tetindex++]);
	return (0);
}

int solve_core(char *piece)
{
	
