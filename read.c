/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japarbs <japarbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:49:05 by jetownle          #+#    #+#             */
/*   Updated: 2019/08/02 02:34:31 by japarbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Takes the given fd and the calculated size of the lines to be read.
**	using GNL to push into the allocated double pointer.
**	Returning the read lines.
*/

// char	**ft_readfd(int fd, size_t size)
// {
// 	char	**gnlread;
// 	char	**temp;

// 	if (!(gnlread = (char **)malloc(sizeof(char *) * (size + 1))))
// 		return (NULL);
// 	temp = gnlread;s
// 	ft_bzero(temp, (size + 1));
// 	temp = gnlread;
// 	while (get_next_line(fd, temp) == 1)
// 		++(temp);
// 	*temp = NULL;
// 	return (gnlread);
// }

/*
**	Takes an FD and reads the lines via GNL, pushed line is stored in Holder.
**	temp is set to gnlread, gnlread is realloced for the new line.
**	The contents are pushed to the new double pointer.
*/

char **ft_readfd(int fd)
{
	char	**gnlread;
	char	**temp;
	char	*holder;
	size_t	count;
	size_t	i;

	if (fd < 0)
		return (NULL);
	count = 0;
	gnlread = NULL;
	while (get_next_line(fd, &holder) == 1)
	{
		printf("holder: %s\n", holder); //testing holder
		i = 0;
		temp = gnlread;
		if (!(gnlread = (char **)ft_memalloc(sizeof(char *) * (++count + 1))))
			return (NULL);
		if (count > 1)
			while (temp[++i - 1])
				gnlread[i - 1] = temp[i - 1];
		gnlread[count - 1] = holder;
	}
	//testing output
	i = 0;
	while (i <= count)
		printf("%s\n", gnlread[i++]);
	return (gnlread);
}