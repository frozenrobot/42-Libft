/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 06:46:46 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/19 10:30:33 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if (p[i] == c)
			return ((char *)&p[i]);
		i++;
	}
	return (NULL);
}
