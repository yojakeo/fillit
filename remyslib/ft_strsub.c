/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:07:36 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/18 19:11:39 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates with malloc and returns a fresh substring from the string given as
** argument. the substring begins at index start and is of size len. if start
** and len aren't refering to a valid substring the behavior is undefined.
** if the allocation fails, returns NULL
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s)
		return (0);
	if (!(sub = ft_memalloc(len + 1)))
		return (0);
	sub = ft_strncpy(sub, (s + start), len);
	return (sub);
}
