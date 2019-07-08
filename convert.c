/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:20:55 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/08 16:21:14 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	key Legend: S is start(anchor), R is right, D is down, U is up, L is left.
**	S is always the upper most left pound of the piece.
**	piece_convert takes the tetrinmo and converts it to a map of the piece
**	using the above legend, S always is at the start
**	..#.  following piece would be formated in *tetrimap[27] as
**	.###  "SDLRR", after each char read it would place that part of the piece.
*/
char	*piece_convert(char **gnlread, static char *tetrimap)
{

}