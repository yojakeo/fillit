/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:49:05 by jetownle          #+#    #+#             */
/*   Updated: 2019/07/13 21:21:09 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_readfd(int fd, size_t size)
{
	char	**gnlread;
	char	**temp;

	if (!(gnlread = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	temp = gnlread;
	ft_bzero(temp, (size + 1));
	temp = gnlread;
	while (get_next_line(fd, temp))
		++(temp);
	(*temp) = ft_strdup("");
	return (gnlread);
}
