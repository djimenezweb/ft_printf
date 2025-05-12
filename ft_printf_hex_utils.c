/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:57:16 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 15:41:50 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

// Writes an unsigned int number as hexadecimal
// Base is passed as a string: "0123456789abcdef" or "0123456789ABCDEF"
void	ft_puthex(unsigned int num, char *base)
{
	char	c;

	if (num / 16 > 0)
		ft_puthex(num / 16, base);
	c = base[num % 16];
	write(1, &c, 1);
}

// Writes a pointer value integer as hexadecimal
void	ft_puthex_ptr(uintptr_t num, char *base)
{
	char	c;

	if (num / 16 > 0)
		ft_puthex_ptr(num / 16, "0123456789abcdef");
	c = base[num % 16];
	write(1, &c, 1);
}

// Writes a pointer by calling puthex_ptr or writing 0.
// uintptr_t is an unsigned int type designed to hold pointer values
void	ft_putptr(void *ptr)
{
	uintptr_t	num;

	num = (uintptr_t)ptr;
	write(1, "0x", 2);
	if (num == 0)
		write(1, "0", 1);
	else
		ft_puthex_ptr(num, "0123456789abcdef");
}
