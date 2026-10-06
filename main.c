/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:35:07 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 12:03:35 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	//char	*s = NULL;
	int		out_libc;
	int		out_ft;
	unsigned int		a;

	a = 4294967295;
	printf("-- Libc\n");
	out_libc = printf("%x", a);
	printf("\n-- FT\n");
	out_ft = ft_printf("%x", a);
	printf("\n-Libc int: %x\n", out_libc);
	printf ("-Ft int: %i\n", out_ft);
	return (0);
}