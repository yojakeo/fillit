/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/08/08 16:19:19 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The home of all calls in Fillit, launches Core functions.
*/

int		fillit(int fd)
{
	char	**gnlread;
	t_map	map;
	t_piece	pieces;

	gnlread = ft_readfd(fd);
	(void)map;
	if (format_core(gnlread, &pieces) == -1)
		return (-1);
	if (solve_core(&pieces, &map) == -1)
		return (-1);
	finish_core(&map, &pieces, gnlread);
	return (0);
}
