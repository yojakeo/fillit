/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetownle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:27:30 by jetownle          #+#    #+#             */
/*   Updated: 2019/05/17 03:26:42 by jetownle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcat() appends string src to the end of dst.  It will append at
** most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
** unless dstsize is 0 or the original dst string was longer than dstsize
** (in practice this should not happen as it means that either dstsize is
** incorrect or that dst is not a proper string)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			j;
	size_t		dst_len;
	size_t		src_len;

	i = ft_strlen(dst);
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (size < dst_len + 1)
		return (src_len + size);
	if (size > dst_len + 1)
	{
		while (i < size - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (dst_len + src_len);
}
