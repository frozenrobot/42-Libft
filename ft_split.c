/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:32:36 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 14:38:22 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft2_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_strcpy(char const *s, int i, char *tab, char c)
{
	int	size;
	int	k;

	size = 0;
	while (s[i + size] != c && s[i + size] != '\0')
		size++;
	tab = malloc((size + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	k = 0;
	while (k < size && s[i + k] != '\0')
	{
		tab[k] = s[i + k];
		k++;
	}
	tab[k] = '\0';
	return (tab);
}

char	**assign(char const *s, char c, char **tab, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < count && i < ft2_strlen(s))
	{
		while (s[i] == c && i < ft2_strlen(s))
			i++;
		tab[j] = ft_strcpy(s, i, tab[j], c);
		if (!tab[j])
		{
			while (j >= 0)
			{
				free(tab[j]);
				j--;
			}
			free(tab);
			return (NULL);
		}
		i += ft2_strlen(tab[j]);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	tab = malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab = assign(s, c, tab, count);
	return (tab);
}
