/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:05:24 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/19 20:54:00 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_array_size(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len += 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len += 1;
	}
	return (len);
}

char	*fill_string(char *str, long n, int i)
{
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		size;
	int		i;

	n = nb;
	size = find_array_size(n);
	i = size;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	return (fill_string(str, n, i - 1));
}
