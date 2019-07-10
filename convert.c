/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:20:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/09 20:59:16 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Converts 21 char strings to "Directional Format"
**	key Legend: S is start(anchor), R is right, D is down, U is up, L is left.
**	S is always the upper most left pound of the piece (height being priority).
**	piece_convert takes the tetromino and converts it to a map of the piece
**	using the above legend, S always is at the start.
**	      The following piece would be formated in *tetrimap[27] as "SDLRR".
**	..#.  After each char read it would place that block of the piece.
**	.###  Essentially guiding the program though the piece from the anchor.
*/

char	*piece_convert(char *tetrimap)
{
	char	*res;
	// char	*tmp;

	res = ft_strdup("S");
	// if (/* condition */)
	// 	tmp = ft_strjoin(res, "R");
	// else if (/* condition */)
	// 	tmp = ft_strjoin(res, "L");
	// else if (/* condition */)
	// 	tmp = ft_strjoin(res, "D");
	// else if (/* condition */)
	// 	tmp = ft_strjoin(res, "U");
	(void)tetrimap;
	return (res);
}
