/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:17:46 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 14:06:47 by kgulati          ###   ########.fr       */
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

char	*find_str(const char *big, const char *little, size_t len, size_t i)
{
	size_t	j;
	size_t	little_len;

	j = 0;
	little_len = ft2_strlen(little);
	while (big[i] && i <= (ft2_strlen(big) - little_len) && i < len)
	{
		if (big[i] == little[0] || little_len == 0)
		{
			j = 0;
			while (j < little_len && i + j < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
			if (j == (little_len))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	return (find_str(big, little, len, i));
}
