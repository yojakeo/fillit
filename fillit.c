/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:26:48 by japarbs           #+#    #+#             */
/*   Updated: 2019/07/01 20:15:34 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(int fd)
{
	char **gnlread;


}
/*
**	Perhaps could use chars to guide the program
*/
char	*piece_convert()
{

}

/*
**		Sudo code / function planning
**	Fillit finds the smallest possible square for up to 26 tetrimenos to fit
**	into via an algorithm.
**
**		Planned modules
**	Function to take GNL's **line and converts & confirms pieces.
**	Perhaps could use chars to guide the program (hjkl,
**
**	Algorithm to make a piece fit within current square.
**
**	To save cycles. Before algorithm starts it'll calculate the smallest
**	possible square within (pieces x 4) rather than starting from 2x2.
**
**	module to display square and the lettered pieces in the square.
**
**	Linked list OR map to keep track of pieces.
**	
*/