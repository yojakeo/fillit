/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:17:04 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:46:10 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;

	ptr = NULL;
	if (size)
	{
		ptr = (char *)malloc(sizeof(char) * size);
		if (!ptr)
			return (NULL);
		else
			ft_bzero(ptr, size);
	}
	return ((void *)ptr);
}
