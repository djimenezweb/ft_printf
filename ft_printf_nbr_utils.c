/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:56:52 by danielji          #+#    #+#             */
/*   Updated: 2025/05/13 11:56:36 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Writes an int number
// Returns number of characters written
ssize_t	ft_putnbr(int n)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (n == -2147483648)
	{
		written += write(1, "-2147483648", 11);
		return (written);
	}
	if (n < 0)
	{
		written += write(1, "-", 1);
		n = n * (-1);
	}
	if (n / 10 > 0)
	{
		written += ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	written += write(1, &c, 1);
	return (written);
}

// Writes an unsigned int number
// Returns number of characters written
ssize_t	ft_putnbr_u(unsigned int n)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (n / 10 > 0)
	{
		written += ft_putnbr_u(n / 10);
	}
	c = (n % 10) + 48;
	written += write(1, &c, 1);
	return (written);
}
