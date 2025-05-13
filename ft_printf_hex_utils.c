/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:57:16 by danielji          #+#    #+#             */
/*   Updated: 2025/05/13 11:56:36 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// Writes an unsigned int number as hexadecimal
// Base is passed as a string: "0123456789abcdef" or "0123456789ABCDEF"
ssize_t	ft_puthex(unsigned int num, char *base)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (num / 16 > 0)
		written += ft_puthex(num / 16, base);
	c = base[num % 16];
	written += write(1, &c, 1);
	return (written);
}

// Writes a pointer value integer as hexadecimal
ssize_t	ft_puthex_ptr(uintptr_t num, char *base)
{
	char	c;
	ssize_t	written;

	written = 0;
	if (num / 16 > 0)
		written += ft_puthex_ptr(num / 16, "0123456789abcdef");
	c = base[num % 16];
	written += write(1, &c, 1);
	return (written);
}

// Writes a pointer by calling puthex_ptr or writing 0.
// uintptr_t is an unsigned int type designed to hold pointer values
ssize_t	ft_putptr(void *ptr)
{
	ssize_t		written;
	uintptr_t	num;

	written = 0;
	if (!ptr)
	{
		written += write(1, "(nil)", 5);
		return (written);
	}
	num = (uintptr_t)ptr;
	written += write(1, "0x", 2);
	if (num == 0)
		written += write(1, "0", 1);
	else
		written += ft_puthex_ptr(num, "0123456789abcdef");
	return (written);
}
