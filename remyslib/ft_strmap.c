/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:50:54 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/20 21:05:10 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string given as argument
** to create a "fresh" new string resulting from the successive applications
** of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*fresh;

	i = 0;
	if (!s || !f)
		return (NULL);
	fresh = ft_strnew(ft_strlen((char *)s));
	if (!fresh)
		return (NULL);
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
