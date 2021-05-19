/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:29:49 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 04:40:14 by kgulati          ###   ########.fr       */
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

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, char const *src, int src_k, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i + src_k] != '\0')
	{
		dest[i] = src[i + src_k];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (is_set(s1[start], set))
		start++;
	end = ft2_strlen(s1) - start;
	if (end != 0)
	{
		while (s1[start + end - 1] && is_set(s1[start + end - 1], set))
			end--;
	}
	trimmed = malloc((end + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	trimmed = ft_strncpy(trimmed, s1, start, end);
	trimmed[end] = '\0';
	return (trimmed);
}
