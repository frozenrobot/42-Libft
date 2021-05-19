/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:17:30 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 04:16:00 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft2_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*both;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft2_strlen(s1) + ft2_strlen(s2);
	both = malloc ((size + 1) * sizeof(char));
	if (!both)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		both[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		both[i + j] = s2[j];
		j++;
	}
	both[i + j] = '\0';
	return (both);
}
