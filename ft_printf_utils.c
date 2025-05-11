/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:23:13 by danielji          #+#    #+#             */
/*   Updated: 2025/05/11 17:14:43 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	c;

	while (*s)
	{
		c = *s;
		write(fd, &c, 1);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	char	c;

	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + 48;
	write(fd, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putitohex_fd(int num, char *base, int fd)
{
	char	c;

	if (num / 16 > 0)
		ft_putitohex_fd(num / 16, base, fd);
	c = base[num % 16];
	write(fd, &c, 1);
}
