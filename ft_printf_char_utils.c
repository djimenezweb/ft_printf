/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:55:50 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 18:39:21 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

// Writes a single character
// Returns number of characters written or -1 if no character
ssize_t	ft_putchar(char c)
{
	ssize_t	written;
	
	if (!c)
		return (-1);
	written = write(1, &c, 1);
	return (written);
}

// Writes a string character by character
// Returns number of characters written or -1 on error
ssize_t	ft_putstr(char *s)
{
	ssize_t	total;
	ssize_t	written;

	if (!s)
		return (-1);
	total = 0;
	while (*s)
	{
		written = write(1, s, 1);
		if (written < 0)
			return (-1);
		total += written;
		s++;
	}
	return (total);
}
