/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:32:32 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:56:37 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates the first occurence of c (converted to an unsigned char)
** in string s, returns a pointer to the byte located or NULL if no
** such byte exists within n bytes
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s)[i] == (unsigned char)c)
			return ((void*)&((unsigned const char *)s)[i]);
		i++;
	}
	return (NULL);
}
