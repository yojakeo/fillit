/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:39:31 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/01 20:14:28 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (-1);
	}
	fd = open(argv);
	fillit(fd);
	return (0);
}

