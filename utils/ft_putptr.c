/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 09:59:56 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/05 13:53:14 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	out;

	if (write (1, "0x", 2) < 0)
		return (-1);
	out = ft_putnbr_hex ((unsigned long long)ptr, 'x');
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