/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:05:24 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/19 14:39:50 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_array_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i += 1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	if (i == 0)
		i = 1;
	return (i);
}

static char	*convert_array(int n, int neg, int size)
{
	char	*array;
	int		i;

	array = malloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	array[size] = '\0';
	i = size - 1;
	if (n == 0)
		array[i] = '0';
	while (n > 0)
	{
		array[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg == -1)
	{
		array[i] = '-';
		i--;
	}
	return ((char *)&array[i + 1]);
}

char	*ft_itoa(int n)
{
	int	neg;
	int	size;
	long nb;

	nb = n;
	neg = 1;
	if (nb < 0)
	{
		neg = -1;
		nb *= -1;
	}
	size = find_array_size(nb);
	return (convert_array(nb, neg, size));
}



#include<stdio.h>
#include<string.h>
int main(void)
{
	// char s2a[] = "0";
	// char s2b[] = "-2147483648";
	// char s2c[] = "2147483647";
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
}
// 	if (!strcmp(ft_itoa(0), s2a) && !strcmp(ft_itoa(-2147483648), s2b) && !strcmp(ft_itoa(2147483647), s2c))
// 		printf("ft_isitoa: OK\n");
// 	else
// 		printf("ft_isitoa: KO\n");
// }

// #include <stdlib.h>
// #include <stdio.h>

// int		len(long nb)
// {
// 	int		len;

// 	len = 0;
// 	if (nb < 0)
// 	{
// 		nb = nb * -1;
// 		len++;
// 	}
// 	while (nb > 0)
// 	{
// 		nb = nb / 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int nb)
// {
// 	char *str;
// 	long	n;
// 	int		i;

// 	n = nb;
// 	i = len(n);
// 	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
// 		return (NULL);
// 	str[i--] = '\0';
// 	if (n == 0)
// 	{
// 		str[0] = 48;
// 		return (str);
// 	}
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		n = n * -1;
// 	}
// 	while (n > 0)
// 	{
// 		str[i] = 48 + (n % 10);
// 		n = n / 10;
// 		i--;
// 	}
// 	return (str);
// }

// // int main(void)
// // {
// // 	printf("%s\n", ft_itoa(-123156));
// // 	return (0);
// // }
