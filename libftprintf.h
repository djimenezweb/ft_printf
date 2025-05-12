/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:24:51 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 14:59:49 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);

// String & Char utils
void	ft_putchar(char c, ssize_t *count);
void	ft_putstr(char *s, ssize_t *count);

// Number utils
void	ft_putnbr(int n);
void	ft_putnbr_u(unsigned int n);

// Hexadecimal utils
void	ft_puthex(unsigned int num, char *base);
void	ft_puthex_ptr(uintptr_t num, char *base);
void	ft_putptr(void *ptr);

#endif