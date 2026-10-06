/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:35:07 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 13:15:06 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	//char	*s = NULL;
	int		out_libc;
	int		out_ft;
	unsigned int		a;

	a = 42;
	printf("-- Libc\n");
	out_libc = printf("%i %%", a);
	printf ("\n-- FT\n");
	out_ft = ft_printf("%i %%", a);
	printf("\n-Libc int: %i\n", out_libc);
	printf ("-Ft int: %i\n", out_ft);
	return (0);
}