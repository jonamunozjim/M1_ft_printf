/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:35:29 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/05 14:43:12 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	check_limits(int nbr)
{
	if (nbr == 0)
	{
		if (write (1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int			i;
	char		s[10];
	int			count;

	count = check_limits (nbr);
	if (count != 0)
		return (count);
	i = 0;
	while (nbr != 0)
	{
		s[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
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
	
    nb = 0;
    ft_putnbr(nb);
    return (0);
}*/