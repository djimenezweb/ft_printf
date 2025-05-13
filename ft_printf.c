/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:12:27 by danielji          #+#    #+#             */
/*   Updated: 2025/05/13 11:56:36 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_putargument(char c, va_list	arg_ptr)
{
	ssize_t	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(arg_ptr, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'u')
		count += ft_putnbr_u(va_arg(arg_ptr, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(arg_ptr, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_puthex(va_arg(arg_ptr, int), "0123456789ABCDEF");
	else if (c == 'p')
		count += ft_putptr(va_arg(arg_ptr, void *));
	else
		return (-1);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg_ptr;
	ssize_t	count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_putargument(str[i + 1], arg_ptr);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arg_ptr);
	return ((int)count);
}

// DELETE OR COMMENT
/* 
# include <stdio.h>
int	main(void)
{
	int result = 0;
	int expected;
	result = ft_printf("%s", "guten abend");
	printf("\n");
	expected = printf("%s", "guten abend");
	printf("\nresult: %d | expected: %d\n", result, expected);
	return (0);
}
*/