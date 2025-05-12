/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:55:50 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 15:45:55 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

// Writes a single character
// Returns number of characters written
ssize_t	ft_putchar(char c)
{
	ssize_t	written;
	
	written = write(1, &c, 1);
	return (written);
}

// Writes a string character by character
// Returns number of characters written
ssize_t	ft_putstr(char *s)
{
	char	c;
	ssize_t	written;
	
	written = 0;
	while (*s)
	{
		c = *s;
		written += write(1, &c, 1);
		s++;
	}
	return (written);
}
