/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:12:27 by danielji          #+#    #+#             */
/*   Updated: 2025/05/11 17:19:38 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

static void putarg(char *str, int i)
{
	
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		fd;
	va_list	arg_ptr;

	i = 0;
	fd = 1;
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				ft_putchar_fd('%', fd);
			else if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(arg_ptr, int), fd);
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(arg_ptr, int), fd);
			else if (str[i + 1] == 'u')
				ft_putnbr_u_fd(va_arg(arg_ptr, unsigned int), fd);
			else if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(arg_ptr, char *), fd);
			else if (str[i + 1] == 'x')
				ft_putitohex_fd(va_arg(arg_ptr, int), "0123456789abcdef", fd);
			else if (str[i + 1] == 'X')
				ft_putitohex_fd(va_arg(arg_ptr, int), "0123456789ABCDEF", fd);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], fd);
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

	printf("%d, %p\n", ptr, &ptr);
	return (0);
}
