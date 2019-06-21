/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:39:31 by jetownle          #+#    #+#             */
/*   Updated: 2019/06/20 19:46:07 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{


	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}

	return (0);
}

