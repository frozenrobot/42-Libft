/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:57:59 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 12:39:34 by kgulati          ###   ########.fr       */
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

char	*ft_strmapi(char const *s, char (*f)(unsigned int n, char c))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	new = malloc((ft2_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < ft2_strlen(s))
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
