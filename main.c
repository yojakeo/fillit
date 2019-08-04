/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:39:31 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/04 01:23:01 by japarbs          ###   ########.fr       */
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
	if (fd < 0 || fillit(fd) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	return (0);
}
