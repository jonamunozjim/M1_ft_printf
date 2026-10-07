/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 09:59:56 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 12:00:35 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
//      Outputs a pointer's memory address to the standard output (stdout) 
// 			in hexadecimal format.
// 
// Parameters:
//      ptr: The pointer whose memory address will be printed.
//
// Return value:
//      Returns the number of characters printed, or -1 if an error occurs.

#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	out;

	if (!ptr)
	{
		if (write (1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	if (write (1, "0x", 2) < 0)
		return (-1);
	out = ft_putnbr_hex ((unsigned long int)ptr, 'x');
	if (out < 0)
		return (-1);
	return (out + 2);
}
/*
int	main(void)
{
	char	s[] = "AsdfHola";

	 ft_putptr(s);
	 printf ("\n%p\n", s);
	 return (0);
}
*/