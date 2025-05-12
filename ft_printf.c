/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:12:27 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 18:40:38 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

ssize_t	ft_putargument(char c, va_list	arg_ptr)
{
	ssize_t	written;

	if (c == '%')
		written = ft_putchar('%');
	else if (c == 'c')
		written = ft_putchar(va_arg(arg_ptr, int));
	else if (c == 's')
		written = ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		written = ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'u')
		written = ft_putnbr_u(va_arg(arg_ptr, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(arg_ptr, int), "0123456789abcdef");
	else if (c == 'X')
		ft_puthex(va_arg(arg_ptr, int), "0123456789ABCDEF");
	else if (c == 'p')
		ft_putptr(va_arg(arg_ptr, void *));
	else
		written = ft_putchar(c);
	return (written);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg_ptr;
	ssize_t	total;
	ssize_t	written;

	i = 0;
	total = 0;
	written = 0;
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			written = ft_putargument(str[i + 1], arg_ptr);
			if (written < 0)
				return (-1);
			total += written;
			i++;
		}
		else
		{
			written = ft_putchar(str[i]);
			if (written < 0)
				return (-1);
			total += written;
		}
		i++;
	}
	va_end(arg_ptr);
	return ((int)total);
}

// DELETE OR COMMENT
int	main(void)
{
	int result = 0;
	result = ft_printf("%s", "Guten Morgen 123!");
	printf("\n%d\n", result);
/* 	int ptr = 4;
	ft_printf("  output -> hola %c%i%% %d, %i, %u, %i, %s, hex1234=%x\n", 'F', 49, 300, -299, 12, -2147483647, "adiós", 1234);
	   printf("expected -> hola %c%i%% %d, %i, %u, %i, %s, hex1234=%x\n", 'F', 49, 300, -299, 12, -2147483647, "adiós", 1234);

	ft_printf("  output -> %d, %p\n", ptr, &ptr);
	   printf("expected -> %d, %p\n", ptr, &ptr);

	ft_printf("  output -> %x\n", 255);
	   printf("expected -> %x\n", 255);

	ft_printf("  output -> %x\n", -10);
	   printf("expected -> %x\n", -10);*/
	return (0);
}
