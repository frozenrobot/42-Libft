/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 08:10:08 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 03:14:14 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft2_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (s)
	{
		i = 0;
		p = (unsigned char *)s;
		while (i < n)
		{
			p[i] = '\0';
			i++;
		}
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	ft2_bzero(array, size * nmemb);
	return (array);
}
