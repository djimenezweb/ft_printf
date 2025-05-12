/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:55:50 by danielji          #+#    #+#             */
/*   Updated: 2025/05/12 15:02:32 by danielji         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libftprintf.h"

// Writes a single character
void	ft_putchar(char c, ssize_t *count)
{
	*count += write(1, &c, 1);
}

// Writes a string character by character
void	ft_putstr(char *s, ssize_t *count)
{
	char	c;

	while (*s)
	{
		c = *s;
		*count += write(1, &c, 1);
		s++;
	}
}
