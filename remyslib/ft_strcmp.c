/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:44:22 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/22 02:12:44 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** lexicographically compares s1 and s2, returns int < > or == 0 after
** comparison, basically... returns an ascii value that can be used
** to alphabatize strings
*/

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 != '\0')
		return ((unsigned char)*s1);
	if (*s2 != '\0')
		return (-*s2);
	return (0);
}
