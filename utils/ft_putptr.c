/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 09:59:56 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 12:17:09 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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