/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:24:51 by danielji          #+#    #+#             */
/*   Updated: 2025/05/11 17:15:09 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_u_fd(unsigned int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putitohex_fd(int num, char *base, int fd);

#endif