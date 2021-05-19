/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:31:06 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 03:14:19 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
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
