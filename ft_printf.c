/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:12:27 by danielji          #+#    #+#             */
/*   Updated: 2025/05/11 23:08:09 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	arg_ptr;

	i = 0;
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				ft_putchar('%');
			else if (str[i + 1] == 'c')
				ft_putchar(va_arg(arg_ptr, int));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr(va_arg(arg_ptr, int));
			else if (str[i + 1] == 'u')
				ft_putnbr_u(va_arg(arg_ptr, unsigned int));
			else if (str[i + 1] == 's')
				ft_putstr(va_arg(arg_ptr, char *));
			else if (str[i + 1] == 'x')
				ft_puthex(va_arg(arg_ptr, int), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				ft_puthex(va_arg(arg_ptr, int), "0123456789ABCDEF");
			else if (str[i + 1] == 'p')
				ft_putptr(va_arg(arg_ptr, void *));
			i++;
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arg_ptr);
	return (0);
}

// DELETE OR COMMENT
int	main(void)
{
	int ptr = 4;
	ft_printf("  output -> hola %c%i%% %d, %i, %u, %i, %s, hex1234=%x\n", 'F', 49, 300, -299, 12, -2147483647, "adiós", 1234);
	   printf("expected -> hola %c%i%% %d, %i, %u, %i, %s, hex1234=%x\n", 'F', 49, 300, -299, 12, -2147483647, "adiós", 1234);

	ft_printf("  output -> %d, %p\n", ptr, &ptr);
	   printf("expected -> %d, %p\n", ptr, &ptr);

	ft_printf("  output -> %x\n", 255);
	   printf("expected -> %x\n", 255);

	ft_printf("  output -> %x\n", -10);
	   printf("expected -> %x\n", -10);
	return (0);
}
