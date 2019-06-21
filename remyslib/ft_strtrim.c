/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 23:53:19 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:55:02 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates with malloc(), and returns a copy of the string given as argument
** without whites paces at the beginning or at the end of the string. will be
** considered as whitespaces the following characters ' ', '\n', and '\t'.
** if s has no white spaces at the beginning or at the end, the function
** returns a copy of s. if the allocation fails the function returns NULL
*/

char	*ft_strtrim(char const *s)
{
	size_t			i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start = i;
	while (s[i] != '\0')
	{
		if (s[i] >= '!' && s[i] <= '~')
			end = i;
		i++;
	}
	if (end == 0)
		return (ft_strnew(1));
	return (ft_strsub(s, start, (size_t)(end - start + 1)));
}
