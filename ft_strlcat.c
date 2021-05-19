/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 07:42:43 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 12:02:40 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft2_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dest;
	size_t	append_size;

	i = 0;
	size_src = ft2_strlen(src);
	size_dest = ft2_strlen(dest);
	append_size = size - size_dest - 1;
	if (size <= size_dest)
		return (size + size_src);
	while (src[i] != '\0' && i < (append_size))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_src + size_dest);
}
