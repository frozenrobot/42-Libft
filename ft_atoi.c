/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:48:23 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/18 03:03:47 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	check_size_ahead(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] <= '9' && str[i + j] >= '0')
	{
		j++;
	}
	return (j);
}

static int	ten_power(int exp)
{
	if (exp == 0)
		return (1);
	return (10 * ten_power(exp - 1));
}

static int	convert_to_int(char *str, int i, int size)
{
	int	result;
	int	j;

	result = 0;
	j = 1;
	while (j <= size)
	{
		result += ((str[i] - '0') * ten_power(size - j));
		i++;
		j++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	multiply;
	int	size;

	if (!str)
		return (0);
	i = 0;
	multiply = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			multiply *= -1;
		i++;
	}
	size = check_size_ahead(str, i);
	return (multiply * convert_to_int(str, i, size));
}
