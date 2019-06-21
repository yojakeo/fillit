/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:27:21 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:51:32 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
	}
}
