/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:21:02 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/15 16:45:55 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” link.
** The variables content and content_size of the new link are initialized by
** copy of the parameters of the function.
** If the parameter content is nul, the variable content is initialized
** to NULL and the variable content_size is initialized to 0 even if the
** parameter content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
