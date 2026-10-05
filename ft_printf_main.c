/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:35:07 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/05 14:42:40 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	char	s[] = "Hola que tal";
	int		out_libc;
	int		out_ft;
	int		a;

	a = 324;
	out_libc = printf("-Libc\n");
	out_libc = printf("%s %p %u\n", s, s, a);
	printf("-- FT\n");
	out_ft = ft_printf("%s %p %u\n", s, s, a);
	printf("-Libc: %i\n-Ft: %i\n", out_libc, out_ft);
	return (0);
}