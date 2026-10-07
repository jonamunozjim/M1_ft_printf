/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:56:53 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 11:56:34 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 		Outputs an integer converted to hex to the standard output (stdout).
// 
// Parameters:
// 		nb, number to be converted
//		c, manage if the output is lowercase (x) or uppercase (X)
//
// Return value:
// 		Returns the number of characters printed, or -1 if an error occurs.

#include "../includes/ft_printf.h"

static int	print_array(int *dec, int i, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	while (i >= 0)
	{
		if (write (1, &hex[dec[i]], 1) < 0)
			return (-1);
		i--;
	}
	return (0);
}

int	ft_putnbr_hex(unsigned long int nb, char c)
{
	int		i;
	int		dec[16];

	i = 0;
	if (nb == 0)
	{
		if (write (1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	while (nb > 0)
	{
		dec[i] = nb % 16;
		nb = nb / 16;
		if (nb != 0)
			i++;
	}
	if (print_array(dec, i, c) < 0)
		return (-1);
	else
		return (i + 1);
}
/*
int main(void)
{
 	unsigned long int nb;
	
    nb = 426;
    ft_putnbr_hex(nb, 'x');
    return (0);
}
*/