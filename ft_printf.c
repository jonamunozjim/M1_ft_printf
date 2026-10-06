/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 12:50:52 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 12:16:55 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
//      xxxxx
// 
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

int ft_printf(char const *s, ...)
{
    va_list         list;
    int             i;
    int             n;
    int             count;
    i = 0;
    count = 0;
    va_start(list, s);
    while (s[i])
    {
        if(s[i] == '%')
        {
            i++;
            if (s[i] == 'c' || s[i] == '%')
                n = ft_putchar(va_arg (list, int)); 
            else if (s[i] == 's')
                n = ft_putstr (va_arg (list, char *));
            else if (s[i] == 'p')
                n = ft_putptr (va_arg (list, void *));
            else if (s[i] == 'i' || s[i] == 'd')
                n = ft_putnbr (va_arg (list, int));
            else if (s[i] == 'x' || s[i] == 'X')
                n = ft_putnbr_hex (va_arg (list, unsigned long int), s[i]);
            else if (s[i] == 'u')
                n = ft_putnbr_unsigned (va_arg (list, unsigned int));
            i++;
        }        
        else
        {
            n = ft_putchar(s[i]);
            i++;
        }
            if (n < 0)
            return (-1);
        else
            count = count + n;
    }    
    va_end(list);
    return (count);
}
