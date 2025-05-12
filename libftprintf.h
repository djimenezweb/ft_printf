/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:24:51 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 16:00:23 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);
ssize_t	ft_putargument(char c, va_list	arg_ptr);

// String & Char utils
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);

// Number utils
ssize_t	ft_putnbr(int n);
ssize_t	ft_putnbr_u(unsigned int n);

// Hexadecimal utils
void	ft_puthex(unsigned int num, char *base);
void	ft_puthex_ptr(uintptr_t num, char *base);
void	ft_putptr(void *ptr);

#endif