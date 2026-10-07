/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:35:29 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 11:58:04 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 		Output an integer to the standard output (stdout).
// 
// Parameters:
// 		nbr, int to be converted
//
// Return value:
// 		Returns the number of characters printed, or -1 if an error occurs.

#include "../includes/ft_printf.h"

static int	check_limits(int nbr)
{
	if (nbr == -2147483648)
	{
		if (write (1, "-2147483648", 11) < 0)
			return (-1);
		return (11);
	}
	if (nbr == 0)
	{
		if (write (1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

static int	put_array(int i, int count, char *s)
{
	while (i >= 0)
	{
		if ((write (1, &s[i], 1) < 0))
			return (-1);
		count++;
		i--;
	}
	return (count);
}

static int	check_sign(int nbr)
{
	if (nbr < 0)
	{
		if (write (1, "-", 1) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_putnbr(int nbr)
{
	int			i;
	char		s[10];
	int			count;

	count = check_limits (nbr);
	if (count != 0)
		return (count);
	i = 0;
	count = count + check_sign (nbr);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		s[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	i--;
	return (put_array (i, count, s));
}
/*
int main(void)
{
 	int nb;
	
    nb = 42;
    ft_putnbr(nb);
    return (0);
}*/