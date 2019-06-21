/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 01:25:38 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:45:34 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f toe ach link to
** create a "fresh" list (using malloc) resulting from the successive
** applications of f. If the application fails, the function returns NULL.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	if (lst != NULL)
	{
		fresh = (t_list*)malloc(sizeof(t_list));
		if (fresh == NULL)
			return (NULL);
		fresh = f(lst);
		fresh->next = ft_lstmap(lst->next, f);
		return (fresh);
	}
	return (NULL);
}
