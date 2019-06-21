/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 01:21:38 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/22 00:58:46 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strnstr locates the first occurence of the null terminated string needle
** in the string haystack, where not more than len characters are searched.
** characters that appear after a '\0' are not searched. if needle is an
** empty string, hackstack is returned, if needle occurs nowhere in haystack,
** null is returned, otherwise a pointer to the first character of the first
** occurence of needle is returned
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && (i + j) < len)
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
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
