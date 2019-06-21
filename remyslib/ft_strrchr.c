/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:12:02 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/20 23:20:06 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = (int)ft_strlen(str);
	while (i > -1)
	{
		if (str[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (NULL);
}
