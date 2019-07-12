/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:49:05 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/11 19:05:58 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_readfd(int fd, size_t size)
{
	char **gnlread;
	char **temp;

	if (!(gnlread = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	temp = gnlread;
	gnlread[size] = NULL;
	while (get_next_line(fd, temp))
	{
		printf("%s\n", *(temp));
		++(temp);
	}
	return (gnlread);
}
