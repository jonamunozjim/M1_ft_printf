/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 14:56:53 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 12:17:03 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_hex(unsigned long int nb, char c)
{
	int		i;
	char	*hex;
	int		dec[16];
	int		count;

	i = 0;
	if (nb == 0)
	{
		if (write (1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	while (nb > 0)
	{
		dec[i] = nb % 16;
		nb = nb / 16;
		if (nb != 0)
			i++;
	}
	count = i + 1;
	while (i >= 0)
	{
		if (write (1, &hex[dec[i]], 1) < 0)
			return (-1);
		i--;
	}
	return (count);
}
/*
int main(void)
{
 	unsigned long int nb;
	
    nb = 426;
    ft_putnbr_hex(nb, 'x');
    return (0);
}*/

