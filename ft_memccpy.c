/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 06:30:40 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/19 11:41:44 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	if (!src || !dest)
		return (NULL);
	i = 0;
	p_dest = (char *)dest;
	p_src = (char *)src;
	while (i < n && !(p_src[i] == (char)c))
	{
		p_dest[i] = p_src[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		p_dest[i] = p_src[i];
		return ((char *)&p_dest[i + 1]);
	}
}
