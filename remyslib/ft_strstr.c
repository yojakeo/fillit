/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:14:42 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:54:40 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strstr fnct finds the first occurrence of the substring needle in the string
** haystack. the terminating null bytes ('\0') are not compared. these functions
** return a pointer to the beginning of the located substring or NULL if the
** substring is not found
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
	{
		return ((char*)haystack);
	}
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char*)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
