/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 12:50:52 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 12:25:28 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
//	* ft_printf produce write output to stdout.
// 	
//	* It reproduce similar function than printf from libc.
//  
//	* ft_print does not manage buffer like printf.
//	
//	* The following convertions are implemented in 
// 		this function: cspdiuxX% (check Parameters description below)
//
// Parameters:
//      char *, the string to be written.
//      ..., arguments to be printed:
//          %c, print a character.
//          %s, print a string.
//          %p, pointer given as (void *) in Hex.
//          %d, for decimal (base 10).
//          %i, for integer (base 10).
//          %u, for hexadecimal (base 10) unsigned.
//          %x, for hexadecimal (base 16) lowercase.
//          %x, for hexadecimal (base 16) uppercase.
//          %%, for % character.
//
// Return value:
//      n, number of characters printed in screen.
//      -1, if error.

#include "includes/ft_printf.h"

int	check_character(char c, va_list list)
{
	int	n;

	n = 0;
	if (c == '%')
		n = ft_putchar('%');
	else if (c == 'c')
		n = ft_putchar(va_arg (list, int));
	else if (c == 's')
		n = ft_putstr (va_arg (list, char *));
	else if (c == 'p')
		n = ft_putptr (va_arg (list, void *));
	else if (c == 'i' || c == 'd')
		n = ft_putnbr (va_arg (list, int));
	else if (c == 'x' || c == 'X')
		n = ft_putnbr_hex (va_arg (list, unsigned int), c);
	else if (c == 'u')
		n = ft_putnbr_unsigned (va_arg (list, unsigned int));
	return (n);
}

int	ft_printf(char const *s, ...)
{
	va_list	list;
	int		i;
	int		n;
	int		count;

	if (!s)
		return (-1);
	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			n = check_character(s[i], list);
		}
		else
			n = ft_putchar(s[i]);
		i++;
		if (n < 0)
			return (-1);
		count = count + n;
	}
	return (va_end(list), count);
}
