/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:39:31 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/22 21:31:41 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fillit(fd) == -1)
		ERROR("ERROR! Something went wrong!", -1)
	// else
	// 	ft_putendl("Should be:\n SRDL\n SDDD\n SRLDD\n SDRLL\n SRRLD\n SRRLLD");
	return (0);
}
