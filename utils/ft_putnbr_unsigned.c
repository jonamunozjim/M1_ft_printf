/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:35:29 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 11:57:27 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 		Output an unsigned integer to the standard output (stdout).
// 
// Parameters:
// 		nbr, unsigned int to be converted
//
// Return value:
// 		Returns the number of characters printed, or -1 if an error occurs.

#include "../includes/ft_printf.h"

static int	put_zero(void)
{
	return (write (1, "0", 1));
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int			i;
	char		s[10];
	int			count;

	if (nbr == 0)
		return (put_zero());
	count = 0;
	i = 0;
	while (nbr > 0)
	{
		s[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		if ((write (1, &s[i], 1) < 0))
			return (-1);
		count++;
		i--;
	}
	return (count);
}
/*
int main(void)
{
 	int nb;
	
    nb = -1;
    ft_putnbr(nb);
    return (0);
}*/