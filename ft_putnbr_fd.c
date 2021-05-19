/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:41:39 by kgulati           #+#    #+#             */
/*   Updated: 2021/05/16 10:52:57 by kgulati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft2_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	check_negative(int nb, int fd)
{
	if (nb < 0)
	{
		ft2_putchar_fd('-', fd);
		nb = -nb;
	}
	return (nb);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	nb = check_negative(nb, fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft2_putchar_fd('0' + nb, fd);
}
