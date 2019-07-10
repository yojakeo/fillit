/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:49:05 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/09 21:36:55 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_readfd(int fd, size_t size)
{
	char **gnlread;

	if (!(gnlread = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (get_net_line(fd, gnlread))
		++(gnlread);
	return (gnlread);
}
